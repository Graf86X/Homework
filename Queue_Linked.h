#ifndef DATA_STRUCTURES_QUEUE_LINKED_H
#define DATA_STRUCTURES_QUEUE_LINKED_H

template<typename Y>
class Queue_Lincked {
    private:
        struct Node {
            Y data;
            Node* next;

            Node(Y add, Node* nextNode = nullptr): data(add), next(nextNode) {}
        };

        Node* frontPtr;
        Node* topPtr;

        void copy(const Queue_Lincked<Y>& other);
        void erase();

    public:
        Queue_Lincked();
        Queue_Lincked(const Queue_Lincked<Y>& other);
        Queue_Lincked<Y>& operator=(const Queue_Lincked<Y>& other);
        ~Queue_Lincked();

        Queue_Lincked(Queue_Lincked<Y>&& other);
        Queue_Lincked<Y>& operator=(Queue_Lincked<Y>&& other);

        void push(Y add);
        void pop();
        Y& front();
        const Y& front() const;
        bool empty() const;
};

// Pomoshtni funkcii

template<typename Y>
void Queue_Lincked<Y>::copy(const Queue_Lincked<Y> &other) {
     if (!other.frontPtr) {
         frontPtr = nullptr;
         topPtr = nullptr;
         return;
     }

    Node* temp = other.frontPtr;
    while (temp != nullptr) {
        push(temp->data);
        temp = temp->next;
    }
}

// O(n)
template<typename Y>
void Queue_Lincked<Y>::erase() {
    while (!empty()) {
        pop();
    }
}

// Rule of 6

template<typename Y>
Queue_Lincked<Y>::Queue_Lincked():frontPtr(nullptr), topPtr(nullptr) {
}

template<typename Y>
Queue_Lincked<Y>::Queue_Lincked(const Queue_Lincked<Y> &other):frontPtr(nullptr), topPtr(nullptr) {
    copy(other);
}

template<typename Y>
Queue_Lincked<Y> & Queue_Lincked<Y>::operator=(const Queue_Lincked<Y> &other) {
    if (this != &other) {
        erase();
        topPtr = frontPtr = nullptr;
        copy(other);
    }

    return *this;
}

template<typename Y>
Queue_Lincked<Y>::~Queue_Lincked() {
    erase();
}

template<typename Y>
Queue_Lincked<Y>::Queue_Lincked(Queue_Lincked<Y> &&other) {
    frontPtr = other.frontPtr;
    topPtr = other.topPtr;

    other.frontPtr = nullptr;
    other.topPtr = nullptr;
}

template<typename Y>
Queue_Lincked<Y> & Queue_Lincked<Y>::operator=(Queue_Lincked<Y> &&other) {
    if (this != &other) {
        erase();
        frontPtr = other.frontPtr;
        topPtr = other.topPtr;

        other.frontPtr = nullptr;
        other.topPtr = nullptr;
    }
    return *this;
}

// Methods

// O(1)
template<typename Y>
void Queue_Lincked<Y>::push(Y add) {
    Node* temp = new Node(add);

    if (empty())
        frontPtr = topPtr = temp;
    else {
        topPtr->next = temp;
        topPtr = temp;
    }
}

// O(1)
template<typename Y>
void Queue_Lincked<Y>::pop() {
    if (empty())
        throw std::underflow_error("Queue is empty");

    Node* temp = frontPtr;
    frontPtr = frontPtr->next;
    delete temp;

    if (frontPtr == nullptr)
        topPtr = nullptr;

}

// O(1)
template<typename Y>
Y & Queue_Lincked<Y>::front() {
    if (empty())
        throw std::underflow_error("Queue is empty");
    return frontPtr->data;
}

// O(1)
template<typename Y>
const Y & Queue_Lincked<Y>::front() const {
    if (empty())
        throw std::underflow_error("Queue is empty");
    return frontPtr->data;
}

// O(1)
template<typename Y>
bool Queue_Lincked<Y>::empty() const {
    return frontPtr == nullptr;
}


#endif //DATA_STRUCTURES_QUEUE_LINKED_H
