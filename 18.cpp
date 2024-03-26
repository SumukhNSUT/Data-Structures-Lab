// Implement a priority queue using linked list
#include <iostream>
using namespace std;
// Node class to represent each element in the priority queue
class Node
{
public:
    int data;
    int priority;
    Node *next;
    Node(int data, int priority)
    {
        this->data = data;
        this->priority = priority;
        this->next = nullptr;
    }
};
// Priority Queue class
class PriorityQueue
{
private:
    Node *front;

public:
    PriorityQueue()
    {
        front = nullptr;
    }
    // Function to check if the priority queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }
    // Function to enqueue an element with its priority to the priority queue
    void enqueue(int data, int priority)
    {
        Node *newNode = new Node(data, priority);
        if (isEmpty() || priority < front->priority)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            Node *temp = front;
            while (temp->next != nullptr && temp->next->priority <=
                                                priority)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        cout << "Enqueued data " << data << " with priority " << priority
             << endl;
    }
    // Function to dequeue the highest priority element from the priority queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Priority queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        Node *temp = front;
        int data = temp->data;
        front = front->next;
        delete temp;
        return data;
    }
    // Function to display the elements of the priority queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Priority queue is empty." << endl;
            return;
        }
        cout << "Elements of priority queue are: ";
        Node *temp = front;
        while (temp != nullptr)
        {
            cout << "(" << temp->data << ", " << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    PriorityQueue pq;
    pq.enqueue(10, 2);
    pq.enqueue(20, 1);
    pq.enqueue(30, 3);
    pq.enqueue(40, 2);
    pq.display();
    cout << "Dequeued element: " << pq.dequeue() << endl;
    pq.display();
    return 0;
}