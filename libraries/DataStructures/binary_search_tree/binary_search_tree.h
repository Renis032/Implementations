#include <stdexcept>

namespace rsm
{

template <typename T>
class binary_search_tree
{
public:
    class Node
    {
    public:
        Node(T value) : value(value){}

        Node* left = nullptr;
        Node* right = nullptr;
        T value;
    };

public:
    void insert(T value)
    {
        Node* newNode = new Node(value);
        if(nullptr == m_root)
        {
            m_root = newNode;
            return;
        }

        Node* temp = m_root;
        while(true)
        {
            if(temp->value == newNode->value)
            {
                return;
            }
            if(newNode->value < temp->value)
            {
                if(temp->left == nullptr)
                {
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            }
            else if(newNode->value > temp->value)
            {
                if(temp->right == nullptr)
                {
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
        }
    }
    bool containsDFS(T value)
    {
        if(nullptr == m_root)
        {
            return false;
        }

        Node* temp = m_root;
        while(temp)
        {
            if(value == temp->value)
            {
                return true;
            }

            if(value < temp->value)
            {
                temp = temp->left;
            }
            else if(value > temp->value)
            {
                temp = temp->right;
            }
        }

        return false;
    }

//    void containsBFS();

    auto get_root() -> Node*
    {
        return m_root;
    }

private:
    Node* m_root = nullptr;
};

} // end of namespace rsm
