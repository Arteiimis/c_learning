
#include<list>
#include<memory> 
using namespace std;

template<class TObject> 
class ObjectPool
{
private:
    std::list<TObject *> pool;
public:
    ObjectPool() = default;
    ~ObjectPool() 
    {
        clear();
    }
    ObjectPool(const ObjectPool &)=delete;
    ObjectPool & operator=(const ObjectPool &) = delete;
public:
    template<class... Args>
    std::shared_ptr<TObject> acquire(Args &&... args)
    {
        if(pool.empty())
        {
            return std::shared_ptr<TObject>(new TObject(std::forward<Args>(args)...),
            [&](TObject *p)
            {
                pool.push_back(p);
            });
        }
        else 
        {
            auto ptr = pool.front();
            pool.pop_front();
            return std::shared_ptr<TObject>(ptr,
            [&](TObject *p)
            {
                pool.push_back(p);
            });
        }
    }
    size_t getSize() const { return pool.size();}
    void clear() 
    {
        for(auto &p : pool)
        {
            delete p;
            p = nullptr;
        }
        pool.clear();
    }
};


