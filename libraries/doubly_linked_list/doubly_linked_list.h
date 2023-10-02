namespace rsm
{

class doubly_linked_list
{
public:
    class Node
    {
    public:
        Node(int value) : value(value){}

        int value;
        Node* nextNode = nullptr;
        Node* prevNode = nullptr;
    };

public:
    doubly_linked_list(int value);

    void append(int value);
    void prepend(int value);
    void insert(int index, int value);

    void reverse();

    void delete_node(int index);
    void delete_first();
    void delete_last();

    void set(int index, int value);
    auto get(int index) -> Node*;

    auto length() -> const int;
    auto get_head() -> const Node*;
    auto get_tail() -> const Node*;
private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
    int m_length = 0;
};

}
