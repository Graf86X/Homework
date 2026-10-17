#ifndef DATA_STRUCTURES_QUEUE_LINKED_H
#define DATA_STRUCTURES_QUEUE_LINKED_H

template<typename Y>
class Queue_Linked {
    private:
        struct Node {
            Y data;
            Node* next;

            Node(Y add, Node* nextNode = nullptr): data(add), next(nextNode) {}
        };

        Node* frontPtr;
        Node* topPtr;

        void copy(const Queue_Linked<Y>& other);
        void erase();

    public:
        Queue_Linked();
        Queue_Linked(const Queue_Linked<Y>& other);
        Queue_Linked<Y>& operator=(const Queue_Linked<Y>& other);
        ~Queue_Linked();

        Queue_Linked(Queue_Linked<Y>&& other);
        Queue_Linked<Y>& operator=(Queue_Linked<Y>&& other);

        void push(Y add);
        void pop();
        Y& front();
        const Y& front() const;
        bool empty() const;
};

// Pomoshtni funkcii

template<typename Y>
void Queue_Linked<Y>::copy(const Queue_Linked<Y> &other) {
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
void Queue_Linked<Y>::erase() {
    while (!empty()) {
        pop();
    }
}

// Rule of 6

template<typename Y>
Queue_Linked<Y>::Queue_Linked():frontPtr(nullptr), topPtr(nullptr) {
}

template<typename Y>
Queue_Linked<Y>::Queue_Linked(const Queue_Linked<Y> &other):frontPtr(nullptr), topPtr(nullptr) {
    copy(other);
}

template<typename Y>
Queue_Linked<Y> & Queue_Linked<Y>::operator=(const Queue_Linked<Y> &other) {
    if (this != &other) {
        erase();
        topPtr = frontPtr = nullptr;
        copy(other);
    }

    return *this;
}

template<typename Y>
Queue_Linked<Y>::~Queue_Linked() {
    erase();
}

template<typename Y>
Queue_Linked<Y>::Queue_Linked(Queue_Linked<Y> &&other) {
    frontPtr = other.frontPtr;
    topPtr = other.topPtr;

    other.frontPtr = nullptr;
    other.topPtr = nullptr;
}

template<typename Y>
Queue_Linked<Y> & Queue_Linked<Y>::operator=(Queue_Linked<Y> &&other) {
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
void Queue_Linked<Y>::push(Y add) {
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
void Queue_Linked<Y>::pop() {
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
Y & Queue_Linked<Y>::front() {
    if (empty())
        throw std::underflow_error("Queue is empty");
    return frontPtr->data;
}

// O(1)
template<typename Y>
const Y & Queue_Linked<Y>::front() const {
    if (empty())
        throw std::underflow_error("Queue is empty");
    return frontPtr->data;
}

// O(1)
template<typename Y>
bool Queue_Linked<Y>::empty() const {
    return frontPtr == nullptr;
}


#endif //DATA_STRUCTURES_QUEUE_LINKED_H
