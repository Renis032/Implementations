#include <cstdint>
#include <utility>

namespace rsm
{

template<typename T>
class shared_ptr
{
public:
    shared_ptr() : ptr(nullptr), refCount(new uint16_t(0)){}
    shared_ptr(T* ptr) : ptr(ptr), refCount(new uint16_t(1)){}

    shared_ptr(const shared_ptr& obj)
    {
        this->ptr = obj.ptr;
        this->refCount = obj.refCount;
        if(nullptr != this->ptr)
        {
            (*this->refCount)++;
        }
    }

    ~shared_ptr()
    {
        if(--(*this->refCount) == 0)
        {
            delete this->ptr;
            delete this->refCount;
        }
    }

    shared_ptr& operator=(const shared_ptr& obj)
    {
        if(this != &obj)
        {
            this->ptr = obj.ptr;
            this->refCount = obj.refCount;
            if(nullptr != this->ptr)
            {
                (*this->refCount)++;
            }
        }
        return *this;
    }

    shared_ptr(shared_ptr&& dyingObj) noexcept
    {
        this->ptr = dyingObj.ptr;
        this->refCount = dyingObj.refCount;
        dyingObj.ptr = nullptr;
        dyingObj.refCount = nullptr;
    }

    T* operator->() const
    {
        return this->ptr;
    }

    T& operator*() const
    {
        return *(this->ptr);
    }

    uint16_t get_count() const
    {
        return *this->refCount;
    }

    T* get() const
    {
        return this->ptr;
    }

    void reset()
    {
        this->ptr = nullptr;
        this->refCount = new uint16_t(0);
    }

private:
    T* ptr = nullptr;
    uint16_t* refCount = nullptr;
};

template<typename T, typename... Args>
shared_ptr<T> make_shared(Args&&... args)
{
    return shared_ptr<T>(new T(std::forward<Args>(args)...));
}

}
