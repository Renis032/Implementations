#include <string>
namespace rsm
{

class hash_table
{
public:
    class Node
    {
    public:
        Node(std::string key, int value) : key(key)
                                         , value(value){}

        std::string key = "";
        int value;
        Node* nextNode = nullptr;
    };
public:
    void print_table();

    void set(const std::string& key, int value);
    auto value(const std::string& key) -> const int;

    auto get_data_map() -> Node*;
    auto hash(const std::string& key) -> const int;
    auto size() -> const int;

private:
    static const int m_size = 7;
    Node* m_dataMap[m_size];
};

} // end of namespace rsm
