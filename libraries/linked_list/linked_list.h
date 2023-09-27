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

    void append(int value);
    void prepend(int value);
    void insert(int index, int value);

    Node* head = nullptr;
private:
    Node* tail = nullptr;
    int m_length = 0;
};

} // rms
