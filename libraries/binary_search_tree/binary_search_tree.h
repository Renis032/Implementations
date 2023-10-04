namespace rsm
{

class binary_search_tree
{
public:
    class Node
    {
    public:
        Node(int value) : value(value){}

        Node* left = nullptr;
        Node* right = nullptr;
        int value;
    };

public:
    binary_search_tree();

    void insert(int value);

    auto get_root() -> Node*;

private:
    Node* m_root;
};

} // end of namespace rsm
