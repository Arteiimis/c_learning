
#include <list>
#include <memory>
using namespace std;

template <class TObject>
class ObjectPool
{
private:
    std::list<TObject *> pool; // idlepool;
    size_t MaxTotal;           // 8
    size_t MaxIdle;            // 4
    size_t totalObject = 0;

    void release(TObject *ptr)
    {
        if (pool.size() < MaxIdle)
        {
            pool.push_back(ptr);
        }
        else
        {
            delete ptr;
            --totalObject;
        }
    }

public:
    ObjectPool(size_t maxtotal = 8, size_t maxidle = 8)
        : MaxTotal(maxtotal), MaxIdle(maxidle)
    {
    }
    ~ObjectPool()
    {
        clear();
    }
    ObjectPool(const ObjectPool &) = delete;
    ObjectPool &operator=(const ObjectPool &) = delete;

public:
    template <class... Args>
    std::shared_ptr<TObject> acquire(Args &&...args)
    {
        if (totalObject < MaxTotal && pool.empty())
        {
            ++totalObject;
            return std::shared_ptr<TObject>(new TObject(std::forward<Args>(args)...),
                                            [&](TObject *p){ release(p); });
        }
        else if(!pool.empty())
        {
            auto ptr = pool.front();
            pool.pop_front();
            return std::shared_ptr<TObject>(ptr,[&](TObject *p){ release(p);});
        }
        else
        {
            return std::shared_ptr<TObject>(nullptr);
        }
    }
    size_t getIdleObjSize() const { return pool.size(); }
    size_t getTotalObjSize() const { return totalObject; }
    size_t getActivateObjSize() const { return totalObject - pool.size(); }
    void clear()
    {
        for (auto &p : pool)
        {
            delete p;
            p = nullptr;
        }
        pool.clear();
    }
};
