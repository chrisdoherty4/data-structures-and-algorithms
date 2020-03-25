#include "dsa/Queue.hpp"

template<typename T>
void Queue<T>::push(T v)
{
    auto p = std::make_shared<Node>(v);

    if (front == nullptr) {
        front = p;
        back = p;
    } else {
        back->next = p;
        p->previous = back;
        back = p;
    }
}

template<typename T>
std::shared_ptr<typename Queue<T>::Node> Queue<T>::pop()
{
    if (front == nullptr) {
        return nullptr;
    } else if (front == back) {
        auto t = front;
        front = back = nullptr;
        return t;
    } else {
        auto t = front;
        front = front->next;
        return t;
    }
}
