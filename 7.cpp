#include <iostream>

// Define a node for the linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize data and next pointer
    Node(int val) : data(val), next(nullptr) {}
};

// Define the LinkedList class
class LinkedList {
private:
    Node* head;

public:
    // Constructor to initialize the head pointer
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the list
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Function to display the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
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
    }
};

int main() {
    // Create a linked list object
    LinkedList list;

    // Insert some elements into the list
    list.insertAtBeginning(5);
    list.insertAtBeginning(10);
    list.insertAtBeginning(15);
    list.insertAtBeginning(20);

    // Display the linked list
    std::cout << "Linked List: ";
    list.display();

    // Delete the linked list
    list.deleteLinkedList();

    return 0;
}
