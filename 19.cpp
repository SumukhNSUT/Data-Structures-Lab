// 19 Implement a double-ended queue using a linked list
#include <iostream>
using namespace std;
// Node class to represent each element in the deque
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
// Deque class
class Deque
{
private:
    Node *front;
    Node *rear;

public:
    Deque()
    {
        front = rear = nullptr;
    }
    // Function to check if the deque is empty
    bool isEmpty()
    {
        return front == nullptr;
    }
    // Function to add an element to the front of the deque
    void insertFront(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << "Inserted " << data << " at the front of deque." << endl;
    }
    // Function to add an element to the rear of the deque
    void insertRear(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        cout << "Inserted " << data << " at the rear of deque." << endl;
    }
    // Function to remove an element from the front of the deque
    int deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty. Cannot delete from front." << endl;
            return -1;
        }
        int data = front->data;
        Node *temp = front;
        front = front->next;
        if (front != nullptr)
        {
            front->prev = nullptr;
        }
        else
        {
            rear = nullptr;
        }
        delete temp;
        return data;
    }
    // Function to remove an element from the rear of the deque
    int deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty. Cannot delete from rear." << endl;
            return -1;
        }
        int data = rear->data;
        Node *temp = rear;
        rear = rear->prev;
        if (rear != nullptr)
        {
            rear->next = nullptr;
        }
        else
        {
            front = nullptr;
        }
        delete temp;
        return data;
    }
    // Function to display the elements of the deque from front to rear
    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return;
        }
        cout << "Elements of deque from front to rear: ";
        Node *temp = front;
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
    Deque dq;
    dq.insertFront(10);
    dq.insertFront(20);
    dq.insertRear(30);
    dq.display();
    cout << "Deleted front element: " << dq.deleteFront() << endl;
    dq.display();
    cout << "Deleted rear element: " << dq.deleteRear() << endl;
    dq.display();
    return 0;
}