// 17 Implement a circular queue using array
#include <iostream>
using namespace std;
class CircularQueue
{
private:
    int *arr;
    int front, rear, capacity;

public:
    CircularQueue(int size)
    {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }
    ~CircularQueue()
    {
        delete[] arr;
    }
    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == -1;
    }
    // Function to check if the queue is full
    bool isFull()
    {
        return (front == 0 && rear == capacity - 1) || (rear == (front -
                                                                 1) %
                                                                    (capacity - 1));
    }
    // Function to enqueue an element to the queue
    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue more elements." << endl;
            return;
        }
        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == capacity - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = data;
        cout << data << " enqueued to queue." << endl;
    }
    // Function to dequeue an element from the queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        int data = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        return data;
    }
    // Function to display the elements of the queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Elements of queue are: ";
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            for (int i = front; i < capacity; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};
int main()
{
    CircularQueue cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();
    cout << "Dequeued element: " << cq.dequeue() << endl;
    cq.display();
    cq.enqueue(40);
    cq.enqueue(50);
    cq.display();
    cq.enqueue(60); // Trying to enqueue when the queue is full
    return 0;
}