#include <bits/stdc++.h>
#include <unistd.h>

template <class T>
class myAllocator
{
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using void_pointer = void*;
    using const_void_pointer = const void*;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using reference = T&;
    using const_reference = const T&;

public:
    size_type max_size() const
    { return std::numeric_limits<size_type>::max(); }

    template<class U, class... Args>
    void construct(U* p, Args&&... args)
    { new(p) U(std::forward<Args>(args)...); }

    template<class U, class... Args>
    void destroy(U* p)
    { p->~U(); }

    template<class U>
    struct rebind
    { using other = myAllocator<U>; };

    myAllocator() = default;
    ~myAllocator() = default;

    pointer allocate(size_type numObj)
    {
        allocCount += numObj;
        std::cout << "myAllocator::allocate, 内存分配: " << numObj << " 个对象, " << "总共分配: " << allocCount << " 个对象\n";
        return static_cast<pointer>(malloc(numObj * sizeof(T)));
    }

    pointer allocate(size_type numObj, const_void_pointer hint)
    { return allocate(numObj); }

    void deallocate(pointer p, size_type numObj)
    {
        allocCount -= numObj;
        std::cout << "myAllocator::deallocate, 内存释放: " << numObj << " 个对象, " << "总共分配: " << allocCount << " 个对象\n";
        free(p);
    }

    size_type getAllocCount() const
    { return allocCount; }

private:
    size_type allocCount;
};

int main()
{
    std::vector<int, myAllocator<int>> v(0);
    for (size_t i = 0; i < 30; i++)
    {
        sleep(1);
        v.push_back(i);
        std::cout << "当前容器占用内存量" << v.get_allocator().getAllocCount() << std::endl;
    }

    return 0;
}