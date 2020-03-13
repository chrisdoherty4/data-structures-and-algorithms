#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <memory>

template <typename T>
struct LinkedList
{
public:
    struct Node;
    typedef std::shared_ptr<Node> node_ptr;

    struct Node
    {        
        T value;
        node_ptr next;

        Node(T value) : value(value), next(nullptr) {}
    };

    node_ptr first;
    node_ptr last;
    
    LinkedList() : first(nullptr) {}
    ~LinkedList() {}

    void add(T value);

    node_ptr find(T value);

    void remove(T value);
};

#endif