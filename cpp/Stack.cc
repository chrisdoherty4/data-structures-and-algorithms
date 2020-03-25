#include "dsa/Stack.hpp"

template <typename T>
void Stack<T>::push(T v) {
    auto p = std::make_shared<Node>(v);

    if (next == nullptr) {
        next = p;
    } else {
        p->next = next;
        next = p;
    }
}

template <typename T>
std::shared_ptr<typename Stack<T>::Node> Stack<T>::pop() {
    if (next == nullptr) {
        return next;
    }

    std::shared_ptr<Node> t = next;
    next = next->next;

    return t;
}