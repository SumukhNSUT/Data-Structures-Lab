// 16 Implement a queue using linked list
#include <iostream>
using namespace std;
// Node class to represent each element in the queue
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
// Queue class
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }
    // Check if the queue is empty
    bool isEmpty()
    {
        return front == nullptr;
        }
    // Enqueue operation to add an element to the rear of the queue
    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        cout << data << " enqueued to queue." << endl;
    }
    // Dequeue operation to remove an element from the front of the queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        int data = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        cout << data << " dequeued from queue." << endl;
        return data;
    }
    // Display the elements of the queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        Node *temp = front;
        cout << "Elements of queue are: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}