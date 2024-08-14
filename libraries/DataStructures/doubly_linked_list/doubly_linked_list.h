#include <stdexcept>

namespace rsm
{

template <typename T>
class doubly_linked_list
{
public:
    class Node
    {
    public:
        Node(T value) : value(value){}

        T value;
        Node* nextNode = nullptr;
        Node* prevNode = nullptr;
    };

public:
    doubly_linked_list(T value)
    {
        Node* node = new Node(value);
        m_head = node;
        m_tail = node;
        m_length = 1;
    }

    void append(T value)
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
            newNode->prevNode = m_tail;
            m_tail = newNode;
        }

        m_length++;
    }
    void prepend(T value)
    {
        Node* newNode = new Node(value);

        if(m_length == 0)
        {
            m_head = newNode;
            m_tail = newNode;
        }
        else
        {
            newNode->nextNode = m_head;
            m_head->prevNode = newNode;
            m_head = newNode;
        }

        m_length++;
    }
    void insert(int index, T value)
    {
        if(index < 0 || index > m_length)
        {
            throw std::out_of_range("Index out of bounds");
            return;
        }
        if(index == 0)
        {
            prepend(value);
            return;
        }
        if(index == m_length)
        {
            append(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = get(index - 1);

        newNode->prevNode = temp;
        newNode->nextNode = temp->nextNode;
        temp->nextNode = newNode;

        m_length++;
    }

    void reverse()
    {
        if(m_length == 0)
        {
            throw std::out_of_range("Index out of bounds");
            return;
        }

        Node* temp = m_head;
        m_head = m_tail;
        m_tail = temp;

        Node* nextNode = temp->nextNode;
        Node* prev = nullptr;

        for(int index = 0; index < m_length; index++)
        {
            nextNode = temp->nextNode;
            temp->nextNode = prev;
            prev = temp;
            temp = nextNode;
            temp->prevNode = prev;
        }
    }

    void delete_node(int index)
    {
        if(index < 0 || index >= m_length)
        {
            return;
        }
        if(index == 0)
        {
            delete_first();
            return;
        }
        if(index == m_length - 1)
        {
            delete_last();
            return;
        }

        Node* temp = get(index);
        Node* prevNode = temp->prevNode;
        Node* nextNode = temp->nextNode;

        delete temp;

        prevNode->nextNode = nextNode;
        nextNode->prevNode = prevNode;

        m_length--;
    }

    void delete_first()
    {
        if(m_length == 0)
        {
            return;
        }
        if(m_length == 1)
        {
            m_head = nullptr;
            m_tail = nullptr;
        }
        else
        {
            Node* temp = m_head;
            m_head = m_head->nextNode;
            m_head->prevNode = nullptr;

            delete temp;
        }

        m_length--;
    }

    void delete_last()
    {
        if(m_length == 0)
        {
            return;
        }
        if(m_length == 1)
        {
            m_head = nullptr;
            m_tail = nullptr;
        }
        else
        {
            Node* temp = m_tail;
            m_tail = m_tail->prevNode;
            m_tail->nextNode = nullptr;

            delete temp;
        }

        m_length--;
    }

    void set(int index, T value)
    {
        Node* temp = get(index);
        if(temp)
        {
            temp->value = value;
        }
    }
    auto get(int index) -> Node*
    {
        if(index < 0 || index >= m_length)
        {
            throw std::out_of_range("Index out of bounds");
            return nullptr;
        }

        Node* temp = m_head;

        if(index / m_length / 2)
        {
            for(int i = 0; i < index; i++)
            {
                temp = temp->nextNode;
            }
        }
        else
        {
            temp = m_tail;
            for(int i = m_length - 1; i > index; i--)
            {
                temp = temp->prevNode;
            }
        }

        return temp;
    }

    auto length() -> const int
    {
        return m_length;
    }
    auto get_head() -> const Node*
    {
        return m_head;
    }
    auto get_tail() -> const Node*
    {
        return m_tail;
    }
private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
    int m_length = 0;
};

} // end of namespace rsm
