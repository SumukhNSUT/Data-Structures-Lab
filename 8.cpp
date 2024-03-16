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

    // Function to delete the first occurrence of a node with given value
    void deleteNode(int val) {
        Node* current = head;
        Node* prev = nullptr;

        // Traverse the list to find the node with the given value
        while (current != nullptr && current->data != val) {
            prev = current;
            current = current->next;
        }

        // If node with value 'val' is found
        if (current != nullptr) {
            // If 'val' is found at the head
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
        }
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

    // Delete a node with value 15
    list.deleteNode(15);

    // Display the linked list after deletion
    std::cout << "Linked List after deletion: ";
    list.display();

    // Delete the linked list
    list.deleteLinkedList();

    return 0;
}
