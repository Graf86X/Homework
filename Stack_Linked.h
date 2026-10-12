#ifndef DATA_STRUCTURES_STACK_LINKED_H
#define DATA_STRUCTURES_STACK_LINKED_H
#include <chrono>
#include <stdexcept>

template<typename Y>
class Stack_Lincked {
    private:
        struct Node {
            Y data;
            Node *next;

            Node(Y add, Node* nextNode=nullptr):data(add), next(nextNode) {}
        };

    Node* topPtr;

    void copy(const Stack_Lincked<Y>& other);
    void erase();

    public:

    Stack_Lincked();
    Stack_Lincked(const Stack_Lincked<Y>& other);
    Stack_Lincked<Y>& operator=(const Stack_Lincked<Y>& other);
    ~Stack_Lincked();

    Stack_Lincked(Stack_Lincked<Y>&& other);
    Stack_Lincked<Y>& operator=(Stack_Lincked<Y>& other);

    void push(Y add);
    void pop();
    Y& top();
    const Y& top()const;
    bool empty() const;
};

// Pomoshtni funkcii

// O(n)
template<typename Y>
void Stack_Lincked<Y>::copy(const Stack_Lincked<Y>& other) {

    if (!other.topPtr) {
        topPtr = nullptr;
        return;
    }

    topPtr = new Node(other.topPtr->data, nullptr);
    Node* next = other.topPtr->link;
    Node* last = topPtr->link;;

    while (next) {
        last = last->link = new Node(next->data, nullptr);
        next = next->link;
    }


}

// O(n)
template<typename Y>
void Stack_Lincked<Y>::erase() {
    while (!empty()) {
        Node* temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
}

// Rule of 6


template<typename Y>
Stack_Lincked<Y>::Stack_Lincked(): topPtr(nullptr) {
}

template<typename Y>
Stack_Lincked<Y>::Stack_Lincked(const Stack_Lincked<Y> &other) {
    copy(other);
}

template<typename Y>
Stack_Lincked<Y> & Stack_Lincked<Y>::operator=(const Stack_Lincked<Y> &other) {
    if (this != &other) {
        copy(other);
        erase();
    }

    return *this;
}

template<typename Y>
Stack_Lincked<Y>::~Stack_Lincked() {
    erase();
}

template<typename Y>
Stack_Lincked<Y>::Stack_Lincked(Stack_Lincked<Y> &&other) {
    topPtr = other.topPtr;
    other.topPtr = nullptr;
}

template<typename Y>
Stack_Lincked<Y> & Stack_Lincked<Y>::operator=(Stack_Lincked<Y> &other) {
    if (this != &other) {
        erase();
        topPtr = other.topPtr;
    }

    return *this;
}

// Methods

// O(1)
template<typename Y>
void Stack_Lincked<Y>::push(Y add) {
    Node* temp = new Node(add, topPtr);
    topPtr = temp;

}

// O(1)
template<typename Y>
void Stack_Lincked<Y>::pop() {
    if (empty())
        throw std::underflow_error("Stack is empty");

    Node* temp = topPtr;
    topPtr = topPtr->next;
    delete temp;
}

// O(1)
template<typename Y>
Y & Stack_Lincked<Y>::top() {
    if (empty())
        throw std::underflow_error("Stack is empty");
    return topPtr->data;
}

// O(1)
template<typename Y>
const Y & Stack_Lincked<Y>::top() const {
    if (empty())
        throw std::underflow_error("Stack is empty");
    return topPtr->data;
}

// O(1)
template<typename Y>
bool Stack_Lincked<Y>::empty() const {
    return topPtr == nullptr;
}


#endif //DATA_STRUCTURES_STACK_LINKED_H
