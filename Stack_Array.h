#ifndef DATA_STRUCTURES_STACK_ARRAY_H
#define DATA_STRUCTURES_STACK_ARRAY_H
#include <stdexcept>

const unsigned int CAPACITY = 1024;
template<typename Y>
class Stack_Array {
    private:
        Y data[CAPACITY];
        unsigned int top_index;


    public:
    Stack_Array();

    void push(Y add);
    void pop();
    Y& top();
    const Y& top()const;
    bool empty() const;
    bool full() const;
};

// Pomoshtni funkcii
template<typename Y>
Stack_Array<Y>::Stack_Array():top_index(0) {

}


// Methods

// O(1)
template<typename Y>
void Stack_Array<Y>::push(Y add) {
    if (full())
        throw std::out_of_range("Stack overflow");

    data[top_index++] = add;
}

// O(1)
template<typename Y>
void Stack_Array<Y>::pop() {
    if (empty())
        throw std::out_of_range("Stack underflow");

    top_index--;
}

// O(1)
template<typename Y>
Y & Stack_Array<Y>::top() {
    if (empty())
        throw std::out_of_range("Stack underflow");

    return data[top_index-1];
}

// O(1)
template<typename Y>
const Y & Stack_Array<Y>::top() const {
    if (empty())
        throw std::out_of_range("Stack underflow");

    return data[top_index-1];
}

// O(1)
template<typename Y>
bool Stack_Array<Y>::empty() const {

    return top_index == 0;
}

// O(1)
template<typename Y>
bool Stack_Array<Y>::full() const {
    return top_index == CAPACITY;
}


#endif //DATA_STRUCTURES_STACK_ARRAY_H
