#ifndef DATA_STRUCTURES_STACK_ARRAY_H
#define DATA_STRUCTURES_STACK_ARRAY_H
#include <stdexcept>

template<typename Y>
class Stack_Dynamic {
    private:
        Y* data;

        unsigned int top_index;
        unsigned int capacity;

        void copy(const Stack_Dynamic<Y>& other);
        void free();

        void resize();

    public:
    Stack_Dynamic();
    Stack_Dynamic(const Stack_Dynamic<Y>& other);
    Stack_Dynamic<Y>& operator=(const Stack_Dynamic<Y>& other);
    ~Stack_Dynamic();

    Stack_Dynamic(Stack_Dynamic<Y>&& other);
    Stack_Dynamic<Y>& operator=(Stack_Dynamic<Y>&& other);

    void push(Y add);
    void pop();
    Y& top();
    const Y& top()const;
    bool empty() const;
};

// Pomoshtni funkcii

// O(n)
template<typename Y>
void Stack_Dynamic<Y>::copy(const Stack_Dynamic<Y> &other) {
    top_index = other.top_index;
    capacity = other.capacity;

    data = capacity > 0 ? new Y[capacity] : nullptr;

    for (unsigned int i = 0; i < top_index; i++) {
        data[i] = other.data[i];
    }
}

// O(1)
template<typename Y>
void Stack_Dynamic<Y>::free() {
    delete[] data;
}

// O(n)
template<typename Y>
void Stack_Dynamic<Y>::resize() {
    if (capacity == 0) {
        capacity = 8;
        data = new Y[capacity];
    } else if (top_index == capacity) {
        capacity *= 2;
        Y* temp = new Y[capacity];
        for (unsigned int i = 0; i < top_index; i++)
            temp[i] = data[i];
        delete[] data;
        data = temp;
    }
}

// Rule of 6

template<typename Y>
Stack_Dynamic<Y>::Stack_Dynamic():data(nullptr), top_index(0), capacity(0) {
}

template<typename Y>
Stack_Dynamic<Y>::Stack_Dynamic(const Stack_Dynamic<Y> &other) {
    copy(other);
}

template<typename Y>
Stack_Dynamic<Y> & Stack_Dynamic<Y>::operator=(const Stack_Dynamic<Y> &other) {
    if (this != &other) {
        free();
        data = nullptr;
        copy(other);
    }

    return *this;
}

template<typename Y>
Stack_Dynamic<Y>::~Stack_Dynamic() {
    free();
}

template<typename Y>
Stack_Dynamic<Y>::Stack_Dynamic(Stack_Dynamic<Y> &&other) {
    data = std::move(other.data);
    top_index = other.top_index;
    capacity = other.capacity;
}

template<typename Y>
Stack_Dynamic<Y> & Stack_Dynamic<Y>::operator=(Stack_Dynamic<Y> &&other) {
    if (this != &other) {
        free();
        data = std::move(other.data);
        top_index = other.top_index;
        capacity = other.capacity;
    }

    return *this;
}

//Methods

// O(1)
template<typename Y>
void Stack_Dynamic<Y>::push(Y add) {
    resize();
    data[top_index++] = add;
}

// O(1)
template<typename Y>
void Stack_Dynamic<Y>::pop() {
    if (empty()) std::__throw_out_of_range("Stack_Dynamic::pop()");
    top_index--;
}

// O(1)
template<typename Y>
Y & Stack_Dynamic<Y>::top() {
    if (empty()) throw std::out_of_range("Stack_Dynamic<Y>::top()");

    return data[top_index-1];
}

// O(1)
template<typename Y>
const Y& Stack_Dynamic<Y>::top() const {
    if (empty()) throw std::out_of_range("Stack_Dynamic<Y>::top()");

    return data[top_index-1];
}

// O(1)
template<typename Y>
bool Stack_Dynamic<Y>::empty() const {
    return top_index == 0;
}


#endif //DATA_STRUCTURES_STACK_ARRAY_H
