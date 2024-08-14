#include <stdexcept>

namespace rsm
{

template <typename T>
class linked_list
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
    linked_list(T headValue)
    {
        Node* newNode = new Node(headValue);
        m_head = newNode;
        m_tail = newNode;
        m_length = 1;
    }
    ~linked_list()
    {
        Node* temp = m_head;
        while(m_head)
        {
            m_head = temp->nextNode;
            delete temp;
            temp = m_head;
        }
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
        }
    }

    void delete_node(int index)
    {
        if(index < 0 || index >= m_length)
        {
            throw std::out_of_range("Index out of bounds");
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

        Node* prevNode = get(index - 1);
        Node* currentNode = get(index);

        prevNode->nextNode = currentNode->nextNode;

        delete currentNode;

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
            Node* temp = m_head->nextNode;
            delete m_head;
            m_head = temp;
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
            Node* temp = m_head;
            Node* prev = m_head;

            while(temp->nextNode)
            {
                prev = temp;
                temp = temp->nextNode;
            }

            m_tail = prev;
            m_tail->nextNode = nullptr;
            delete temp;
        }

        m_length--;
    }

    void set(int index, T value)
    {
        auto temp = get(index);
        temp->value = value;
    }
    auto get(int index) -> Node*
    {
        if(index < 0 || index >= m_length)
        {
            throw std::out_of_range("Index out of bounds");
            return nullptr;
        }

        Node* temp = m_head;

        int nodeCounter = 0;
        while(nodeCounter < index)
        {
            temp = temp->nextNode;
            nodeCounter++;
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
