#include <iostream>

class Queue {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    // Constructor to initialize front and rear indices
    Queue() : front(-1), rear(-1) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    // Function to enqueue an element into the queue
    void enqueue(int val) {
        if (isFull()) {
            std::cout << "Queue overflow!" << std::endl;
            return;
        }
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % MAX_SIZE;
        arr[rear] = val;
        std::cout << val << " enqueued to queue." << std::endl;
    }

    // Function to dequeue an element from the queue
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue underflow!" << std::endl;
            return -1; // or throw an exception
        }
        int dequeued = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX_SIZE;
        return dequeued;
    }

    // Function to return the front element of the queue without removing it
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return -1; // or throw an exception
        }
        return arr[front];
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Front element: " << queue.peek() << std::endl;

    std::cout << "Dequeued element: " << queue.dequeue() << std::endl;
    std::cout << "Dequeued element: " << queue.dequeue() << std::endl;

    std::cout << "Front element: " << queue.peek() << std::endl;

    queue.enqueue(40);

    std::cout << "Front element: " << queue.peek() << std::endl;

    return 0;
}
