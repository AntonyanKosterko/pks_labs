#ifndef MyStack_h
#define MyStack_h

template<class INF, class FRIEND>
class ListNode {
private:
    INF d;
    ListNode *next;
    ListNode(void) { next = nullptr; }
    friend FRIEND;
};

template<class INF>
class MyStack {
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node *top;
public:
    MyStack(void);
    MyStack(const MyStack<INF>& other);
    ~MyStack(void);
    bool empty(void);
    bool push(INF n);
    bool pop(void);
    INF top_inf(void);
};

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

// Конструктор копирования
template<class INF>
MyStack<INF>::MyStack(const MyStack<INF>& other) : top(nullptr) {
    if (!other.empty()) {
        Node* otherTop = other.top;
        Node* newNode = new Node();
        newNode->d = otherTop->d;
        newNode->next = nullptr;
        top = newNode;

        Node* current = top;
        Node* otherCurrent = otherTop->next;
        while (otherCurrent != nullptr) {
            Node* newNextNode = new Node();
            newNextNode->d = otherCurrent->d;
            newNextNode->next = nullptr;
            current->next = newNextNode;

            current = newNextNode;
            otherCurrent = otherCurrent->next;
        }
    }
}

#endif
