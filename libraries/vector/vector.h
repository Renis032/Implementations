#include <cstddef>

namespace rsm
{

class vector
{
public:
    vector();
    ~vector();

    vector& operator =(vector const& obj);
    bool operator ==(vector const& obj);
    bool operator !=(vector const& obj);
    int& operator [](int index);

    // TODO:
    // copy constuctor vec(vec)
    // move constructor
    // move assignment
    // swap between two vectors
    // erase

    int front();
    int back();

    void reserve(int capacityToReserve);
    void resize(int indexToResizeTo);
    void clear();
    void shrink_to_fit();

    void push_back(int elementToPush);
    void pop_back();

    int& at(int index);

    int size() const;
    int capacity() const;

    bool empty() const;
private:
    int *m_array;
    size_t m_capacity = 1;
    size_t m_size = 0;
};

} // rms
