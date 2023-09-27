namespace rms
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
    linked_list(int value);
    ~linked_list();

    void append(int value);
    void prepend(int value);
    void insert(int index, int value);

    auto length() -> const int;

    auto get_head() -> const Node*;
    auto get_tail() -> const Node*;

private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int m_length = 0;
};

} // rms
