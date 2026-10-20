#ifndef DATA_STRUCTURES_DEQUE_H
#define DATA_STRUCTURES_DEQUE_H
#include <stdexcept>

template<typename Y>
class Deque {
    private:
        struct Node {
            Y data;
            Node* prev;
            Node* next;

            Node(Y add, Node* f_ptr=nullptr, Node* b_ptr = nullptr):data(add),prev(f_ptr), next(b_ptr) {};
        };

        Node* frontPtr;
        Node* backPtr;

        void copy(const Deque& other);
        void erase();
    public:

    Deque();
    Deque(const Deque& other);
    Deque& operator=(const Deque& other);
    ~Deque();

    Deque(Deque&& other);
    Deque& operator=(Deque&& other);

    void push_front(Y data);
    void push_back(Y data);
    void pop_front();
    void pop_back();
    Y& front();
    Y& back();
    const Y& front() const;
    const Y& back() const;
    bool empty() const;
};

// Pomoshtni funkcii

template<typename Y>
void Deque<Y>::copy(const Deque<Y> &other) {

    Node* temp = other.frontPtr;
    while (temp != nullptr) {
        push_back(temp->data);
        temp = temp->next;
    }
}

// O(n)
template<typename Y>
void Deque<Y>::erase() {
    while (!empty())
        pop_front();
}

// Rule of 6
template<typename Y>
Deque<Y>::Deque(): frontPtr(nullptr), backPtr(nullptr) {
}

template<typename Y>
Deque<Y>::Deque(const Deque &other):frontPtr(nullptr), backPtr(nullptr) {
    copy(other);
}

template<typename Y>
Deque<Y> & Deque<Y>::operator=(const Deque &other) {
    if (this != &other) {
        erase();
        frontPtr = backPtr = nullptr;
        copy(other);
    }

    return *this;
}

template<typename Y>
Deque<Y>::~Deque() {
    erase();
}

template<typename Y>
Deque<Y>::Deque(Deque &&other):frontPtr(other.frontPtr), backPtr(other.backPtr) {
    other.frontPtr = other.backPtr = nullptr;
}

template<typename Y>
Deque<Y> & Deque<Y>::operator=(Deque &&other) {
    if (this != &other) {
        erase();
        frontPtr = other.frontPtr;
        backPtr = other.backPtr;
        other.frontPtr = other.backPtr = nullptr;
    }

    return *this;
}

// Methods

// O(1)
template<typename Y>
void Deque<Y>::push_front(Y data) {
    Node* temp = new Node(data, nullptr, frontPtr);
    if (frontPtr == nullptr)
        backPtr = temp;
    else
        frontPtr->prev = temp;
    frontPtr = temp;
}

// O(1)
template<typename Y>
void Deque<Y>::push_back(Y data) {
    Node* temp = new Node(data, backPtr, nullptr);
    if (backPtr == nullptr)
        frontPtr = temp;
    else
        backPtr->next = temp;
    backPtr = temp;

}

// O(1)
template<typename Y>
void Deque<Y>::pop_front() {
    if (empty())
        throw std::out_of_range("Deque is empty");

    Node* temp = frontPtr;
    frontPtr = frontPtr->next;

    if (frontPtr == nullptr)
        backPtr = nullptr;
    else
        frontPtr->prev = nullptr;

    delete temp;
}

// O(1)
template<typename Y>
void Deque<Y>::pop_back() {
    if (empty())
        throw std::out_of_range("Deque is empty");

    Node* temp = backPtr;
    backPtr = backPtr->prev;

    if (backPtr == nullptr)
        frontPtr = nullptr;
    else
        backPtr->next = nullptr;

    delete temp;
}

// O(1)
template<typename Y>
Y& Deque<Y>::front() {
    if (empty())
        throw std::out_of_range("Deque is empty");
    return frontPtr->data;
}

// O(1)
template<typename Y>
Y& Deque<Y>::back() {
    if (empty())
        throw std::out_of_range("Deque is empty");
    return backPtr->data;
}

// O(1)
template<typename Y>
const Y& Deque<Y>::front() const {
    if (empty())
        throw std::out_of_range("Deque is empty");
    return frontPtr->data;
}

// O(1)
template<typename Y>
const Y& Deque<Y>::back() const {
    if (empty())
        throw std::out_of_range("Deque is empty");
    return backPtr->data;
}

// O(1)
template<typename Y>
bool Deque<Y>::empty() const {
    return frontPtr == nullptr;
}

#endif //DATA_STRUCTURES_DEQUE_H