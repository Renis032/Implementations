#include <cstddef>
#include <stdexcept>

namespace rsm
{

template <typename T>
class vector
{
public:
    vector()
    {
        m_array = new T[1];
    }
    ~vector()
    {
        delete[] m_array;
    }

    vector<T>& operator =(vector<T> const& obj)
    {
        m_size = obj.m_size;
        m_capacity = obj.m_capacity;

        delete [] m_array;
        m_array = new T[m_capacity];

        for(int idx = 0; idx < m_size; idx++)
        {
            m_array[idx] = obj.m_array[idx];
        }

        return *this;
    }

    bool operator ==(vector<T> const& obj)
    {
        bool result = false;
        if(m_size == obj.size() &&
           m_capacity == obj.capacity())
        {
            result = true;
            for(int idx = 0; idx < m_size; idx++)
            {
                if(m_array[idx] != obj.m_array[idx])
                {
                    result = false;
                    return result;
                }
            }
        }

        return result;
    }

    bool operator !=(vector<T> const& obj)
    {
        return !(*this==obj);
    }

    T& operator [](int index)
    {
        return m_array[index];
    }

    // TODO:
    // copy constuctor vec(vec)
    // move constructor
    // move assignment
    // swap between two vectors
    // erase

    T& front()
    {
        if(m_size > 0)
        {
            return m_array[0];
        }

        throw std::invalid_argument("Vector empty.");
    }

    T& back()
    {
        if(m_size > 0)
        {
            return m_array[m_size - 1];
        }

        throw std::invalid_argument("Vector empty.");
    }

    void reserve(int capacityToReserve)
    {
        m_capacity = capacityToReserve;
        delete [] m_array;
        m_array = new T[m_capacity];
    }

    void resize(int indexToResizeTo)
    {
        if(m_capacity < indexToResizeTo)
        {
            while(m_capacity < indexToResizeTo)
            {
                m_capacity *= 2;
            }
        }
        else if(m_size < m_capacity / 2)
        {
            while(m_size < m_capacity / 2)
            {
                m_capacity /= 2;
            }
        }

        int* temp = new T[m_capacity];
        for(size_t i = 0; i < indexToResizeTo; i++)
        {
            temp[i] = 0;
        }

        for(size_t i = 0; i < m_size; i++)
        {
            temp[i] = m_array[i];
        }

        m_size = indexToResizeTo;

        delete[] m_array;
        m_array = temp;
    }

    void clear()
    {
        delete[] m_array;
        m_array = new T[1];
        m_size = 0;
    }

    void shrink_to_fit()
    {
        m_capacity = m_size;

        T* temp = new T[m_capacity];

        for (size_t i = 0; i < m_size; i++)
        {
            temp[i] = m_array[i];
        }

        delete[] m_array;
        m_array = temp;
    }

    void push_back(T elementToPush)
    {
        if(m_size == m_capacity)
        {
            m_capacity *= 2;
            T* temp = new T[m_capacity];

            for (size_t i = 0; i < m_size; i++)
            {
                temp[i] = m_array[i];
            }

            delete[] m_array;
            m_array = temp;
        }

        m_array[m_size] = elementToPush;
        m_size++;
    }
    void pop_back()
    {
        //TODO:
        // HANDLE STRANGE NUMBERS AFTER SHRINK
        m_size--;
        if(m_size <= m_capacity / 2)
        {
            m_capacity /= 2;
            int* temp = new T[m_capacity];

            for (size_t i = 0; i < m_size; i++)
            {
                temp[i] = m_array[i];
            }

            delete[] m_array;
            m_array = temp;
        }
    }

    T& at(int index)
    {
        if(index < m_size)
        {
            return m_array[index];
        }

        throw std::invalid_argument("Index out of bounds");
    }

    size_t size() const
    {
        return m_size;
    }

    size_t capacity() const
    {
        return m_capacity;
    }

    bool empty() const
    {
        return m_size == 0;
    }

private:
    T* m_array;
    size_t m_capacity = 1;
    size_t m_size = 0;
};

} // rms
