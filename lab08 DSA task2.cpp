#include <iostream>
using namespace std;

class Inventory {
public:
    int serialNum;
    int manufactYear;
    int lotNum;
    Inventory* next;

    Inventory(int serial, int year, int lot) {
        serialNum = serial;
        manufactYear = year;
        lotNum = lot;
        next = NULL;
    }
};

class InventoryStack {
private:
    Inventory* top;

public:
    InventoryStack() {
        top = NULL;
    }

    void push(int serial, int year, int lot) {
        Inventory* newPart = new Inventory(serial, year, lot);
        newPart->next = top;
        top = newPart;
        cout << "Part added to inventory.\n";
    }

    void pop() {
        if (top == NULL) {
            cout << "Inventory is empty. No part to remove.\n";
            return;
        }
        Inventory* temp = top;
        cout << "Removed Part Details:\n";
        cout << "Serial Number: " << temp->serialNum << endl;
        cout << "Manufacturing Year: " << temp->manufactYear << endl;
        cout << "Lot Number: " << temp->lotNum << endl;
        top = top->next;
        delete temp;
    }

    void display() {
        if (top == NULL) {
            cout << "Inventory is empty.\n";
            return;
        }
        cout << "Remaining Parts in Inventory:\n";
        Inventory* temp = top;
        while (temp != NULL) {
            cout << "Serial Number: " << temp->serialNum
                 << ", Manufacturing Year: " << temp->manufactYear
                 << ", Lot Number: " << temp->lotNum << endl;
            temp = temp->next;
        }
    }
};

int main() {
    InventoryStack inventory;
    int choice;

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add part to inventory\n";
        cout << "2. Remove part from inventory\n";
        cout << "3. Display inventory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int serial, year, lot;
            cout << "Enter Serial Number: ";
            cin >> serial;
            cout << "Enter Manufacturing Year: ";
            cin >> year;
            cout << "Enter Lot Number: ";
            cin >> lot;
            inventory.push(serial, year, lot);
        } 
        else if (choice == 2) {
            inventory.pop();
        } 
        else if (choice == 3) {
            inventory.display();
        } 
        else if (choice != 4) {
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    cout << "\nFinal Inventory Status:\n";
    inventory.display();
    cout << "Program exited.\n";

    return 0;
}

