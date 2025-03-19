#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class CircularLinkedList {
private:
    Node* tail; 

public:
    CircularLinkedList() { tail = NULL; } 
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (tail == NULL) { 
            tail = newNode;
            tail->next = tail;
        } else { 
            newNode->next = tail->next;
            tail->next = newNode;
        }
        cout << value << " inserted at the beginning.\n";
    }
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (tail == NULL) {       
            tail = newNode;
            tail->next = tail;
        } else { // Insert at end
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode; // Update tail
        }
        cout << value << " inserted at the end.\n";
    }
    void deleteNode(int value) {
        if (tail == NULL) { 
            cout << "List is empty!\n";
            return;
        }

        Node* curr = tail->next;
        Node* prev = tail;
        if (curr == tail && curr->data == value) {
            delete curr;
            tail = NULL;
            cout << value << " deleted successfully.\n";
            return;
        }
        do {
            if (curr->data == value) {
                prev->next = curr->next;
                if (curr == tail) 
                    tail = prev;
                delete curr;
                cout << value << " deleted successfully.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);

        cout << value << " not found in the list.\n";
    }
    void display() {
        if (tail == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = tail->next;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << " (circular)\n";
    }
};
int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtBeginning(5);
    cll.display();
    cll.deleteNode(20);
    cll.display();
    cll.deleteNode(5);
    cll.display();

    return 0;
}

