
#include <list>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <iostream>

using namespace std;

template<class TObject>
class ObjectPool
{
private:
    std::list<TObject*> pool;      // idle-pool;    空闲的对象
    size_t MaxTotal;                // 8             对象池中最大的对象数
    size_t MaxIdle;                 // 4             对象池中最大的空闲对象数
    size_t totalObject = 0;         //               对象池中对象的统计总数
    std::mutex m_mutex;             //               互斥锁
    std::condition_variable m_cv;   //               条件变量

    /**
     * @brief 释放对象, 将对象放入到空闲对象池中
     *        如果空闲对象池中的对象数目大于最大空闲对象数, 则删除该对象
     * @param ptr 待释放的对象
     */
    void release(TObject* ptr)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        cout << "call release " << endl;

        // 此时对象池中的对象数小于最大空闲对象数,
        // 则将对象放入到空闲对象池中, 等待分配, 并通知等待的线程.
        if (pool.size() < MaxIdle) { pool.push_back(ptr); }
        else    // 此时对象池中的对象数大于最大空闲对象数, 则删除该对象
        {
            delete ptr;
            --totalObject;
            cout << "delete ptr" << endl;
        }

        m_cv.notify_all();
    }

public:
    explicit ObjectPool(size_t maxtotal = 8, size_t maxidle = 8)
            : MaxTotal(maxtotal), MaxIdle(maxidle) { }
    ~ObjectPool() { clear(); }
    ObjectPool(const ObjectPool&) = delete; // 禁止拷贝构造
    ObjectPool& operator=(const ObjectPool&) = delete;  // 禁止赋值

public:
    /**
     * @brief 从对象池中获取对象, 如果对象池中没有空闲对象, 则创建新的对象.
     *        如果对象池中的对象数目大于最大对象数, 则阻塞等待, 直到有空闲对象.
     *        如果对象池中的对象数目小于最大对象数, 则创建新的对象, 并返回.
     *
     * @tparam Args 可变参数模板, 用于构造对象.
     * @param args 可变参数模板, 用于构造对象.
     * @return 线程池中可用的对象.
     */
    template<class... Args>
    std::shared_ptr<TObject> acquire(Args&& ...args)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        cout << "acquire..." << endl;

        m_cv.wait(lock,
                  [&]() -> bool { return !pool.empty() || totalObject < MaxTotal; });

        // ↓此时对象池为空, 且对象池中的对象总数小于最大对象数, 则创建新的对象然后返回.
        if (totalObject < MaxTotal && pool.empty())
        {
            ++totalObject;  // ←增加对象池中对象的统计总数
            // ↓返回一个指向对象的智能指针, 并指定一个删除器, 用于在对象不再被使用时释放对象.
            return std::shared_ptr<TObject>(new TObject(std::forward<Args>(args)...),
                                            [&](TObject* p) { release(p); });
        }
        else if (!pool.empty()) // ←此时对象池中有空闲对象可分配.
        {
            auto ptr = pool.front();    // ←获取空闲对象
            pool.pop_front();           // ←从空闲对象池中移除该对象
            // ↓将该对象封装到一个智能指针中, 并指定一个删除器, 用于在对象不再被使用时释放对象.
            return std::shared_ptr<TObject>(ptr, [&](TObject* p) { release(p); });
        }
        else // ←此时对象池中的对象总数已经达到最大对象数, 且对象池中没有空闲对象可分配.
        {
            return std::shared_ptr<TObject>(nullptr);
        }
    }

    size_t getIdleObjSize() const { return pool.size(); }
    size_t getTotalObjSize() const { return totalObject; }
    size_t getActivateObjSize() const { return totalObject - pool.size(); }

    void clear()
    {
        for (auto& p: pool)
        {
            delete p;
            p = nullptr;
        }
        pool.clear();
    }
};
