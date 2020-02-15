#include <memory>
#include "dsa/LinkedList.hpp"

template <typename T>
void LinkedList<T>::append(T& v)
{

    node_ptr n = std::make_shared<Node>(v);

    if (first == NULL) {
        first = n;
        return;
    }

    node_ptr temp = first;
    while (temp.next != NULL)
        temp = temp->next;

    temp->next = n;
}

template <typename T>
void LinkedList<T>::remove(T& v)
{
    if (first->value == v) {
        first = first->next;
    }

    node_ptr temp = first;

    while (temp->next != nullptr && temp->next->value != v)
        temp = temp->next;

    if (temp->next != nullptr) {
        if (temp->next->next == nullptr) {
            temp->next = nullptr;
        } else {
            temp->next = temp->next->next;
        }
    }
}