#include <cstddef>

namespace rsm
{

class vector
{
public:
    vector();
    ~vector();

    // TODO:
    // copy constuctor vec(vec)
    // copy assignment =
    // move constructor
    // move assignment
    // == operator
    // != operator
    // swap between two vectors

    void reserve(int capacityToReserve);
    void resize(int indexToResizeTo);

    void push_back(int elementToPush);
    void pop_back();

    int at(int index);

    int size() const;
    int capacity() const;

    bool empty();
private:
    int *m_array;
    size_t m_capacity = 1;
    size_t m_size = 0;
};
}
