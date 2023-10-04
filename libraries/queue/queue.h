namespace rsm
{

class queue
{
public:
    class Node
    {
    public:
        Node(int value) : value(value){}

        int value;
        Node* nextNode = nullptr;
    };

public:
    queue(int value);

    void enqueue(int value);
    void dequeue();

    auto get_first() -> Node*;
    auto get_last() -> Node*;

    auto get_length() -> const int;

private:
    Node* m_first;
    Node* m_last;
    int m_length = 0;
};

} // end of namespace rsm
