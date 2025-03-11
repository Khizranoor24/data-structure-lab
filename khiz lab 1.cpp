#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        cout << "Deleted node at beginning.\n";
    }

    void deleteAfterValue(int value) {
        Node* temp = head;
        while (temp != NULL && temp->data != value) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            cout << "No node found after value " << value << " to delete.\n";
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        if (nodeToDelete->next != NULL) {
            nodeToDelete->next->prev = temp;
        }
        delete nodeToDelete;
        cout << "Deleted node after value " << value << ".\n";
    }

    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Doubly Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(45);
    dll.insertAtEnd(30);
    dll.insertAtEnd(50);
    cout << "Before deletion:\n";
    dll.display();
    dll.deleteAtBeginning();
    cout << "After deleting first node:\n";
    dll.display();
    dll.deleteAfterValue(45);
    cout << "After deleting node after 45:\n";
    dll.display();
    return 0;
}
