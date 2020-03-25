#ifndef QUEUE_H
#define QUEUE_H

#include <memory>

template <typename T>
class Queue
{
public:
    struct Node
    {
        T value;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> previous;

        Node(T v) : value(v), next(nullptr), previous(nullptr) {}
    };

    Queue() : front(nullptr), back(nullptr) {};

private:
    std::shared_ptr<Node> front;
    std::shared_ptr<Node> back;

    void push(T v);
    std::shared_ptr<Node> pop();
};

#endif