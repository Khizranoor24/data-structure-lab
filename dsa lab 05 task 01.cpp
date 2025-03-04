#include <iostream>
using namespace std;

// Structure of a Node in Doubly Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;
    
    // Constructor to initialize the node
    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor to initialize the list as empty
    DoublyLinkedList() {
        head = NULL;
    }

    // Function to add a node at the beginning
    void addAtBeginning(int value) {
        Node* newNode = new Node(value);  // Create a new node with the given value
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to add a node after a given value (45 in this case)
    void addAfterValue(int value, int newValue) {
        Node* temp = head;
        
        // Traverse the list to find the node with the given value
        while (temp != NULL && temp->data != value) {
            temp = temp->next;
        }

        // If the value is found, insert the new node after it
        if (temp != NULL) {
            Node* newNode = new Node(newValue);
            newNode->next = temp->next;
            newNode->prev = temp;

            // If the node after the current node is not null, update its previous pointer
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        } else {
            cout << "Value " << value << " not found in the list.\n";
        }
    }

    // Function to display the list
    void display() {
        if (head == NULL) {
            cout << "The list is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    int n, mark;
    
    // Take user input to initialize the list
    cout << "Enter the number of marks to be entered: ";
    cin >> n;

    cout << "Enter the marks: ";
    for (int i = 0; i < n; i++) {
        cin >> mark;
        list.addAtBeginning(mark);
    }

    // Display the list after initialization
    cout << "The initial list is: ";
    list.display();

    // Add a node after the value 45
    int newMark;
    cout << "Enter the mark to add after 45: ";
    cin >> newMark;
    list.addAfterValue(45, newMark);

    // Display the list after adding new value after 45
    cout << "The list after adding the mark after 45: ";
    list.display();

    return 0;
}

