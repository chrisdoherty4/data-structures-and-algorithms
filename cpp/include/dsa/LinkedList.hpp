#include <memory>

template <typename T>
struct LinkedList
{
    struct Node;
    typedef std::shared_ptr<Node> node_ptr;

    struct Node
    {        
        T value;
        node_ptr next;

        Node(T& value) : value(value), next(nullptr) {}
    };

    node_ptr first;

    LinkedList() : first(nullptr) {}
    ~LinkedList() {}
    void append(T&);
    void remove(T&);
};