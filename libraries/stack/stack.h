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

private:
    Node* top = nullptr;
    int m_length = 0;
};

}
