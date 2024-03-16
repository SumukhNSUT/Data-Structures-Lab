#include <iostream>

class Stack {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;

public:
    // Constructor to initialize the top of the stack
    Stack() : top(-1) {}

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // Function to push an element onto the stack
    void push(int val) {
        if (isFull()) {
            std::cout << "Stack overflow!" << std::endl;
            return;
        }
        arr[++top] = val;
        std::cout << val << " pushed to stack." << std::endl;
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow!" << std::endl;
            return -1;
        }
        return arr[top--];
    }

    // Function to return the top element of the stack without removing it
    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        return arr[top];
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.peek() << std::endl;

    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "Popped element: " << stack.pop() << std::endl;

    std::cout << "Top element: " << stack.peek() << std::endl;

    stack.push(40);

    std::cout << "Top element: " << stack.peek() << std::endl;

    return 0;
}
