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

private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int length = 0;
};

} // rms
