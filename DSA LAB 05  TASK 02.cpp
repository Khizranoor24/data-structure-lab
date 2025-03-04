#include <iostream>
using namespace std;

// Structure of a Node in Doubly Linked List
struct Node {
    float data;
    Node* prev;
    Node* next;
    
    Node(float value) {
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

    // Function to add a node at the end of the list
    void addNode(float value) {
        Node* newNode = new Node(value);
        
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Function to calculate total rainfall
    float totalRainfall() {
        float total = 0;
        Node* temp = head;
        while (temp != NULL) {
            total += temp->data;
            temp = temp->next;
        }
        return total;
    }

    // Function to calculate average rainfall
    float averageRainfall() {
        float total = totalRainfall();
        return total / 7;
    }

    // Function to find the highest and lowest rainfall day
    void findMaxMinRainfall() {
        float maxRainfall = head->data;
        float minRainfall = head->data;
        Node* temp = head;
        int maxDay = 1, minDay = 1;
        int day = 1;

        while (temp != NULL) {
            if (temp->data > maxRainfall) {
                maxRainfall = temp->data;
                maxDay = day;
            }
            if (temp->data < minRainfall) {
                minRainfall = temp->data;
                minDay = day;
            }
            temp = temp->next;
            day++;
        }

        cout << "Highest rainfall: " << maxRainfall << " on Day " << maxDay << endl;
        cout << "Lowest rainfall: " << minRainfall << " on Day " << minDay << endl;
    }

    // Function to get rainfall of the day after the 5th node
    void rainfallAfter5thNode() {
        Node* temp = head;
        int count = 1;
        while (temp != NULL && count < 5) {
            temp = temp->next;
            count++;
        }
        
        if (temp != NULL && temp->next != NULL) {
            cout << "Rainfall of the day after the 5th day: " << temp->next->data << endl;
        } else {
            cout << "No data available for the day after the 5th day." << endl;
        }
    }

    // Function to display the list
    void display() {
        Node* temp = head;
        int day = 1;
        while (temp != NULL) {
            cout << "Day " << day << ": " << temp->data << " mm" << endl;
            temp = temp->next;
            day++;
        }
    }
};

int main() {
    DoublyLinkedList list;
    float rainfall;
    
    // Input rainfall for 7 days with validation
    cout << "Enter the rainfall for 7 days (in mm). Negative values will be rejected:" << endl;
    for (int i = 0; i < 7; i++) {
        do {
            cout << "Day " << i + 1 << ": ";
            cin >> rainfall;
            if (rainfall < 0) {
                cout << "Rainfall cannot be negative. Please enter a valid value." << endl;
            }
        } while (rainfall < 0);  // Keep asking for valid input
        
        list.addNode(rainfall);
    }

    // Display the list
    cout << "\nThe rainfall data for the week is:" << endl;
    list.display();
    
    // Calculate and display total rainfall
    cout << "\nTotal rainfall for the week: " << list.totalRainfall() << " mm" << endl;

    // Calculate and display average rainfall
    cout << "Average rainfall for the week: " << list.averageRainfall() << " mm" << endl;

    // Find and display the highest and lowest rainfall day
    list.findMaxMinRainfall();

    // Display the rainfall of the day after the 5th day
    list.rainfallAfter5thNode();

    return 0;
}

