#include <memory>
#include "dsa/LinkedList.hpp"

template <typename T>
void LinkedList<T>::add(T v)
{
    node_ptr n = std::make_shared<Node>(v);

    if (first == NULL) {
        first = n;
        last = first;
        return;
    }

    last->next = n;
    last = n;
}

template <typename T>
void LinkedList<T>::remove(T v)
{
    if (first->value == v) {
        first = first->next;
    }

    node_ptr temp = first;

    while (temp->next != nullptr && temp->next->value != v)
        temp = temp->next;

    // If we've hit the end of the linked list then return because
    // the element didn't exist.
    if (temp->next == nullptr)
        return;

    temp->next = temp->next->next;
    
    if (temp->next == nullptr)
        last = temp;
}

template <typename T>
typename LinkedList<T>::node_ptr LinkedList<T>::find(T v)
{
    if (first->value == v) {
        return first->value;
    }

    node_ptr p = first;
    
    while (p->next != nullptr && p->next != v)
        p = p->next;

    return p->next;
}