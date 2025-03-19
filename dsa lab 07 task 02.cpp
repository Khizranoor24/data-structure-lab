#include <iostream>
using namespace std;
struct Node {
    string name;
    Node* next;
};
class EmployeeList {
private:
    Node* tail; 

public:
    EmployeeList() { tail = NULL; } 
    void addEmployee(string empName) {
        Node* newNode = new Node();
        newNode->name = empName;

        if (tail == NULL) { 
            tail = newNode;
            tail->next = tail;
        } else { 
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode; 
        }
        cout << empName << " added successfully.\n";
    }
    void removeEmployee(string empName) {
        if (tail == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* curr = tail->next;
        Node* prev = tail;
        if (curr == tail && curr->name == empName) {
            delete curr;
            tail = NULL;
            cout << empName << " removed successfully.\n";
            return;
        }
        do {
            if (curr->name == empName) {
                prev->next = curr->next;
                if (curr == tail) 
                    tail = prev;
                delete curr;
                cout << empName << " removed successfully.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);

        cout << empName << " not found!\n";
    }
    void searchEmployee(string empName) {
        if (tail == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = tail->next;
        do {
            if (temp->name == empName) {
                cout << empName << " is in the company.\n";
                return;
            }
            temp = temp->next;
        } while (temp != tail->next);

        cout << empName << " not found!\n";
    }
    void showEmployees() {
        if (tail == NULL) {
            cout << "No employees in the company.\n";
            return;
        }
        Node* temp = tail->next;
        cout << "Employee List: ";
        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << " (circular list)\n";
    }
};

int main() {
    EmployeeList company;
    company.addEmployee("Ayesha");
    company.addEmployee("Amna");
    company.addEmployee("Furqan");
    company.showEmployees();
    company.searchEmployee("Amna");
    company.searchEmployee("Esha");
    company.removeEmployee("Amna");
    company.showEmployees();
    company.removeEmployee("Esha");

    return 0;
}

