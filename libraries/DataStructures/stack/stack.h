#include <stdexcept>

namespace rsm
{

template <typename T>
class stack
{
private:
class Node
{
public:
    Node(T value) : value(value){}

    T value;
    Node* nextNode = nullptr;
};
public:
    stack(T value)
    {
        Node* newNode = new Node(value);
        m_top = newNode;
        m_height = 1;
    }

    void push(T value)
    {
        Node* newNode = new Node(value);
        newNode->nextNode = m_top;
        m_top = newNode;

        m_height++;
    }
    void pop()
    {
        if(m_height == 0)
        {
            throw std::out_of_range("No elements to pop");
        }

        Node* temp = m_top;
        m_top = temp->nextNode;
        delete temp;

        m_height--;
    }

    auto get_top() -> Node*
    {
        return m_top;
    }

    auto height() -> const int
    {
        return m_height;
    }

private:
    Node* m_top = nullptr;
    int m_height = 0;
};

} // end of namespace rsm
