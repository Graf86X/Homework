#ifndef DATA_STRUCTURES_QUEUE_ARRAY_H
#define DATA_STRUCTURES_QUEUE_ARRAY_H
#include <stdexcept>

const unsigned int CAPACITY = 1024;

template<typename Y>
class Queue_Array {
    private:
        Y data[CAPACITY];
        unsigned int front_index;
        unsigned int top_index;
    public:
        Queue_Array();

        void push(Y add);
        void pop();
        Y& top();
        const Y& top() const;
        bool empty() const;
        bool full() const;
};

template<typename Y>
Queue_Array<Y>::Queue_Array():front_index(0), top_index(0) {
}

// Methods

// O(1)
template<typename Y>
void Queue_Array<Y>::push(Y add) {
    if (full())
        throw std::out_of_range("Queue overflow");

    data[top_index] = add;
    top_index = (top_index + 1) % CAPACITY;
}

// O(1)
template<typename Y>
void Queue_Array<Y>::pop() {
    if (empty())
        throw std::out_of_range("Queue underflow");

    front_index = (front_index + 1) % CAPACITY;
}

// O(1)
template<typename Y>
Y & Queue_Array<Y>::top() {
    if (empty())
        throw std::out_of_range("Queue underflow");

    return data[front_index];
}

// O(1)
template<typename Y>
const Y & Queue_Array<Y>::top() const {
    if (empty())
        throw std::out_of_range("Queue underflow");

    return data[front_index];
}

// O(1)
template<typename Y>
bool Queue_Array<Y>::empty() const {
    return top_index == front_index;
}

// O(1)
template<typename Y>
bool Queue_Array<Y>::full() const {
    return top_index == (front_index+CAPACITY-1)%CAPACITY;
}

#endif //DATA_STRUCTURES_QUEUE_ARRAY_H
