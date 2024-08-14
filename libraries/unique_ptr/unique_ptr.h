#include <utility>
namespace rsm
{

template<typename T>

class unique_ptr
{
public:
    unique_ptr() : ptr(nullptr){}
    unique_ptr(T* ptr) : ptr(ptr){}

    ~unique_ptr()
    {
        delete ptr;
    }

    unique_ptr(const unique_ptr& obj) = delete;
    unique_ptr& operator=(const unique_ptr& obj) = delete;

    unique_ptr(unique_ptr&& dyingObj)
    {
        this->ptr = dyingObj.ptr;
        dyingObj.ptr = nullptr;
    }

    void operator=(unique_ptr&& dyingObj)
    {
        this->ptr = dyingObj.ptr;
        dyingObj.ptr = nullptr;
    }

    T* operator->()
    {
        return this->ptr;
    }

    T& operator*()
    {
        return *(this->ptr);
    }

    T* release()
    {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    void reset(T* newPtr = nullptr)
    {
        delete ptr;
        ptr = newPtr;
    }

    void swap(unique_ptr& newPtr)
    {
        T* temp = this->ptr;
        this->ptr = newPtr.ptr;
        newPtr.ptr = temp;
    }

    T* get()
    {
        return ptr;
    }

private:
    T* ptr = nullptr;
};

template<typename T, typename... Args>
unique_ptr<T> make_unique(Args&&... args)
{
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

}