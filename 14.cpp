#include <iostream>

// Define a node for the stack
struct Node {
    int data;
    Node* next;

    // Constructor to initialize data and next pointer
    Node(int val) : data(val), next(nullptr) {}
};

// Define the Stack class
class Stack {
private:
    Node* top;

public:
    // Constructor to initialize the top pointer
    Stack() : top(nullptr) {}

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to push an element onto the stack
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        std::cout << val << " pushed to stack." << std::endl;
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow!" << std::endl;
            return -1; // or throw an exception
        }
        int popped = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return popped;
    }

    // Function to return the top element of the stack without removing it
    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return -1; // or throw an exception
        }
        return top->data;
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
