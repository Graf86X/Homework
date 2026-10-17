#ifndef DATA_STRUCTURES_STACK_LINKED_H
#define DATA_STRUCTURES_STACK_LINKED_H
#include <chrono>
#include <stdexcept>

template<typename Y>
class Stack_Linked {
    private:
        struct Node {
            Y data;
            Node *next;

            Node(Y add, Node* nextNode=nullptr):data(add), next(nextNode) {}
        };

    Node* topPtr;

    void copy(const Stack_Linked<Y>& other);
    void erase();

    public:

    Stack_Linked();
    Stack_Linked(const Stack_Linked<Y>& other);
    Stack_Linked<Y>& operator=(const Stack_Linked<Y>& other);
    ~Stack_Linked();

    Stack_Linked(Stack_Linked<Y>&& other);
    Stack_Linked<Y>& operator=(Stack_Linked<Y>& other);

    void push(Y add);
    void pop();
    Y& top();
    const Y& top()const;
    bool empty() const;
};

// Pomoshtni funkcii

// O(n)
template<typename Y>
void Stack_Linked<Y>::copy(const Stack_Linked<Y>& other) {

   if (!other.topPtr) {
       topPtr = nullptr;
       return;
   }

    topPtr = new Node(other.topPtr->data, nullptr);
    Node* curr = other.topPtr->next;
    Node* prev = topPtr;

    while (curr) {
        prev = prev->next = new Node(curr->data, nullptr);
        curr = curr->next;
    }
}

// O(n)
template<typename Y>
void Stack_Linked<Y>::erase() {
    while (!empty()) {
        pop();
    }
}

// Rule of 6


template<typename Y>
Stack_Linked<Y>::Stack_Linked(): topPtr(nullptr) {
}

template<typename Y>
Stack_Linked<Y>::Stack_Linked(const Stack_Linked<Y> &other) {
    copy(other);
}

template<typename Y>
Stack_Linked<Y> & Stack_Linked<Y>::operator=(const Stack_Linked<Y> &other) {
    if (this != &other) {
        copy(other);
        erase();
    }

    return *this;
}

template<typename Y>
Stack_Linked<Y>::~Stack_Linked() {
    erase();
}

template<typename Y>
Stack_Linked<Y>::Stack_Linked(Stack_Linked<Y> &&other) {
    topPtr = other.topPtr;
    other.topPtr = nullptr;
}

template<typename Y>
Stack_Linked<Y> & Stack_Linked<Y>::operator=(Stack_Linked<Y> &other) {
    if (this != &other) {
        erase();
        topPtr = other.topPtr;
    }

    return *this;
}

// Methods

// O(1)
template<typename Y>
void Stack_Linked<Y>::push(Y add) {
    Node* temp = new Node(add, topPtr);
    topPtr = temp;

}

// O(1)
template<typename Y>
void Stack_Linked<Y>::pop() {
    if (empty())
        throw std::underflow_error("Stack is empty");

    Node* temp = topPtr;
    topPtr = topPtr->next;
    delete temp;
}

// O(1)
template<typename Y>
Y & Stack_Linked<Y>::top() {
    if (empty())
        throw std::underflow_error("Stack is empty");
    return topPtr->data;
}

// O(1)
template<typename Y>
const Y & Stack_Linked<Y>::top() const {
    if (empty())
        throw std::underflow_error("Stack is empty");
    return topPtr->data;
}

// O(1)
template<typename Y>
bool Stack_Linked<Y>::empty() const {
    return topPtr == nullptr;
}


#endif //DATA_STRUCTURES_STACK_LINKED_H
