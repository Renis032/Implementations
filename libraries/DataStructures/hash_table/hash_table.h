#include "../vector/vector.h"
#include <string>
#include <iostream>

namespace rsm
{

template <typename T>
class hash_table
{
public:
    class Node
    {
    public:
        Node(std::string key, T value) : key(key)
                                         , value(value){}

        std::string key = "";
        T value;
        Node* nextNode = nullptr;
    };
public:
    void print_table()
    {
        for(int i = 0; i < size(); i++)
        {
            std::cout << i << ":" << std::endl;
            if(m_dataMap[i])
            {
                Node* temp = m_dataMap[i];
                while(temp)
                {
                    std::cout << "  {" << temp->key << ", " << temp->value << "}" << std::endl;
                    temp = temp->nextNode;
                }
            }
        }
    }

    void set(const std::string& key, T value)
    {
        int index = hash(key);
        Node* newNode = new Node(key, value);
        if(nullptr == m_dataMap[index])
        {
            m_dataMap[index] = newNode;
            return;
        }

        Node* temp = m_dataMap[index];
        while(nullptr != temp->nextNode)
        {
            temp = temp->nextNode;
        }
        temp->nextNode = newNode;
    }
    auto value(const std::string& key) -> const int
    {
        int index = hash(key);
        Node* temp = m_dataMap[index];
        while(nullptr != temp)
        {
            if(temp->key == key)
            {
                return temp->value;
            }
            temp = temp->nextNode;
        }

        return -1;
    }

    auto keys() -> const vector<std::string>
    {
        vector<std::string> allKeys;
        for(int idx = 0; idx < m_size; idx++)
        {
            Node* temp = m_dataMap[idx];
            while(nullptr != temp)
            {
                allKeys.push_back(temp->key);
                temp = temp->nextNode;
            }
        }

        return allKeys;
    }

    auto get_data_map() -> Node*
    {
        return *m_dataMap;
    }
    auto hash(const std::string& key) -> const int
    {
        int hash = 0;

        for(int idx = 0; idx < key.length(); ++idx)
        {
            int asciiValue = int(key[idx]);
            hash = (hash + asciiValue * 23) % size();
        }

        return hash;
    }
    auto size() -> const int
    {
        return m_size;
    }

private:
    static const int m_size = 7;
    Node* m_dataMap[m_size];
};

} // end of namespace rsm
