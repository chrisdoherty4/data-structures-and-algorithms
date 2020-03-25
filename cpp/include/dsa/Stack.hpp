#ifndef STACK_H
#define STACK_H

#include <memory>

template <typename T>
class Stack
{
public:
    struct Node
    {
        T value;
        std::shared_ptr<Node> next;

        Node(T v) : value(v), next(nullptr) {};
    };

    std::shared_ptr<Node> next;

    Stack() : next(nullptr) {}

    void push(T v);
    std::shared_ptr<Node> pop();
};

#endif