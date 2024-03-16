#include <iostream>

// Define a node for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
    
    // Constructor to initialize data, prev, and next pointers
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Define the DoublyLinkedList class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor to initialize the head and tail pointers
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert a new node at the beginning of the list
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to insert a new node at the end of the list
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to display the linked list in forward direction
    void displayForward() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Function to display the linked list in backward direction
    void displayBackward() {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    // Function to delete the entire linked list to free memory
    void deleteLinkedList() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    // Create a doubly linked list object
    DoublyLinkedList list;

    // Insert some elements into the list
    list.insertAtBeginning(5);
    list.insertAtBeginning(10);
    list.insertAtEnd(15);
    list.insertAtEnd(20);

    // Display the linked list in forward direction
    std::cout << "Linked List (Forward): ";
    list.displayForward();

    // Display the linked list in backward direction
    std::cout << "Linked List (Backward): ";
    list.displayBackward();

    // Delete the linked list
    list.deleteLinkedList();

    return 0;
}
