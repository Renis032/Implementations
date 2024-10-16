#include <stdexcept>

namespace rsm
{

template <typename T>
class queue
{

private:
struct Node
{
public:
    Node(T value) : value(value){}

    T value;
    Node* nextNode = nullptr;
};

public:
    queue() : m_head(nullptr), m_tail(nullptr), m_length(0) {}
    queue(T value)
    {
        Node* newNode = new Node(value);
        m_head = newNode;
        m_tail = newNode;
        m_length = 1;
    }

    void enqueue(T value)
    {
        Node* newNode = new Node(value);
        if(m_length == 0)
        {
            m_head = newNode;
            m_tail = newNode;
        }
        else
        {
            m_tail->nextNode = newNode;
            m_tail = newNode;
        }

        m_length++;
    }

    void dequeue()
    {
        if(m_length == 0)
        {
            throw std::out_of_range("No elements to dequeue");
        }
        if(m_length == 1)
        {
            m_head = nullptr;
            m_tail = nullptr;
            m_length--;
            return;
        }

        Node* firstNode = get_head();
        m_head = firstNode->nextNode;
        delete firstNode;

        m_length--;
    }

    bool empty()
    {
        return m_length == 0;
    }

    auto get_head() -> Node*
    {
        return m_head;
    }

    auto get_tail() -> Node*
    {
        return m_tail;
    }

    auto get_length() -> const int
    {
        return m_length;
    }

private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
    int m_length = 0;
};

} // end of namespace rsm
