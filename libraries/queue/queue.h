#include <stdexcept>

namespace rsm
{

template <typename T>
class queue
{
public:
    class Node
    {
    public:
        Node(T value) : value(value){}

        T value;
        Node* nextNode = nullptr;
    };

public:
    queue();
    queue(T value)
    {
        Node* newNode = new Node(value);
        m_first = newNode;
        m_last = newNode;
        m_length = 1;
    }

    void enqueue(T value)
    {
        Node* newNode = new Node(value);
        if(m_length == 0)
        {
            m_first = newNode;
            m_last = newNode;
        }
        else
        {
            m_last->nextNode = newNode;
            m_last = newNode;
        }

        m_length++;
    }

    void dequeue()
    {
        if(m_length == 0)
        {
            throw std::invalid_argument("No elements to dequeue");
        }
        if(m_length == 1)
        {
            m_first = nullptr;
            m_last = nullptr;
            return;
        }

        Node* firstNode = get_first();
        m_first = firstNode->nextNode;
        delete firstNode;

        m_length--;
    }

    auto get_first() -> Node*
    {
        return m_first;
    }

    auto get_last() -> Node*
    {
        return m_last;
    }

    auto get_length() -> const int
    {
        return m_length;
    }

private:
    Node* m_first;
    Node* m_last;
    int m_length = 0;
};

} // end of namespace rsm
