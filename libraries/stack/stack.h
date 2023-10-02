namespace rsm
{

class stack
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
    stack(int value);

    void push(int value);

    auto get_top() -> Node*;

    auto height() -> const int;

private:
    Node* m_top = nullptr;
    int m_height = 0;
};

}
