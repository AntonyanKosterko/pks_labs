#include "MyStack.h"

template<class INF>
MyStack<INF>::MyStack(void) : top(nullptr) {}

template<class INF>
MyStack<INF>::~MyStack(void) {
    while (top != nullptr) {
        pop();
    }
}

template<class INF>
bool MyStack<INF>::empty(void) {
    return top == nullptr;
}

template<class INF>
bool MyStack<INF>::push(INF n) {
    Node *newNode = new Node();
    if (newNode == nullptr) {
        return false;
    }
    newNode->d = n;
    newNode->next = top;
    top = newNode;
    return true;
}

template<class INF>
bool MyStack<INF>::pop(void) {
    if (empty()) {
        return false;
    }
    Node *temp = top;
    top = top->next;
    delete temp;
    return true;
}

template<class INF>
INF MyStack<INF>::top_inf(void) {
    if (empty()) {
        throw "Stack is empty!";
    }
    return top->d;
}
