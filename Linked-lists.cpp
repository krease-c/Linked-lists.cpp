#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;       // Data part
    Node* next;     // Pointer to the next node

    Node(int value) : data(value), next(NULL) {} // Constructor
};

// LinkedList class
class LinkedList {
private:
    Node* head; // Pointer to the head of the list

public:
    LinkedList() : head(NULL) {} // Constructor initializes head to NULL

    // Method to insert a new node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value); // Create a new node
        if (head == NULL) {
            head = newNode; // If list is empty, new node becomes the head
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next; // Traverse to the end of the list
            }
            temp->next = newNode; // Link the new node at the end
        }
    }

    // Method to display the list
    void display() const {
        Node* temp = head; // Start from the head
        while (temp != NULL) {
            cout << temp->data << " -> "; // Print data
            temp = temp->next; // Move to the next node
        }
        cout << "NULL" << endl; // End of the list
    }

    // Method to delete a node by value
    void deleteValue(int value) {
        if (head == NULL) return; // If list is empty

        if (head->data == value) { // If the head needs to be deleted
            Node* temp = head;
            head = head->next; // Move head to the next node
            delete temp; // Free the old head
            return;
        }

        Node* current = head;
        while (current->next != NULL && current->next->data != value) {
            current = current->next; // Traverse the list
        }

        if (current->next == NULL) {
            cout << "Value not found!" << endl; // Value not found
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next; // Bypass the node to be deleted
        delete temp; // Free the deleted node
    }

    // Destructor to free the memory used by the list
    ~LinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current; // Free current node
            current = nextNode; // Move to the next node
        }
    }
};

int main() {
    LinkedList list;

    // Inserting elements into the list
    list.insert(10);
    list.insert(20);
    list.insert(30);

    // Display the list
    cout << "Current linked list: ";
    list.display();

    // Deleting a value
    list.deleteValue(20);
    cout << "After deleting 20: ";
    list.display();

    // Attempting to delete a non-existing value
    list.deleteValue(40);

    return 0;
}

