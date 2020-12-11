#include "stack.h"

stack::stack() {
    head = nullptr;
}

void stack::push(char val) {

    if (head == nullptr) {

        head = new node(val);
        return;
    }

    node* tmp = head;
    head = new node(val);
    head->setNext(tmp);
}

char stack::pop() {
    if (head == nullptr) return -1;
    node* tmp = head;
    head = head->getNext();
    char retval = tmp->getValue();
    return retval;
}

char stack::top() {
    if (head == nullptr)
    {
        return -1;
    }

    return head->getValue();
}
