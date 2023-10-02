namespace rsm
{

class Node
{
public:
    Node(int value) : value(value){}

    int value;
    Node* nextNode = nullptr;
};

class linked_list
{
public:
    linked_list(int headValue);
    ~linked_list();

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

} // rms
