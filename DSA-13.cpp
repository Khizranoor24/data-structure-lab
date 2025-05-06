#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    int empNumber;
    string name;
    double salary;

    Employee(int number, string name, double salary) {
        this->empNumber = number;
        this->name = name;
        this->salary = salary;
    }

    void display() {
        cout << "Emp#: " << empNumber << ", Name: " << name << ", Salary: " << salary << endl;
    }
};

class Node {
public:
    Employee* emp;
    Node* left;
    Node* right;

    Node(Employee* emp) {
        this->emp = emp;
        left = right = NULL;
    }
};

class EmployeeBST {
private:
    Node* root;

    Node* insertRec(Node* root, Employee* emp) {
        if (root == NULL)
            return new Node(emp);

        if (emp->empNumber < root->emp->empNumber)
            root->left = insertRec(root->left, emp);
        else
            root->right = insertRec(root->right, emp);

        return root;
    }

    Node* searchRec(Node* root, int empNumber) {
        if (root == NULL || root->emp->empNumber == empNumber)
            return root;

        if (empNumber < root->emp->empNumber)
            return searchRec(root->left, empNumber);
        else
            return searchRec(root->right, empNumber);
    }

    Node* getMin(Node* node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node* deleteRec(Node* root, int empNumber) {
        if (root == NULL) return NULL;

        if (empNumber < root->emp->empNumber) {
            root->left = deleteRec(root->left, empNumber);
        } else if (empNumber > root->emp->empNumber) {
            root->right = deleteRec(root->right, empNumber);
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* minNode = getMin(root->right);
            root->emp = minNode->emp;
            root->right = deleteRec(root->right, minNode->emp->empNumber);
        }

        return root;
    }

    void inOrderRec(Node* root) {
        if (root != NULL) {
            inOrderRec(root->left);
            root->emp->display();
            inOrderRec(root->right);
        }
    }

    void preOrderRec(Node* root) {
        if (root != NULL) {
            root->emp->display();
            preOrderRec(root->left);
            preOrderRec(root->right);
        }
    }

    void postOrderRec(Node* root) {
        if (root != NULL) {
            postOrderRec(root->left);
            postOrderRec(root->right);
            root->emp->display();
        }
    }

public:
    EmployeeBST() {
        root = NULL;
    }

    void insert(Employee* emp) {
        root = insertRec(root, emp);
    }

    Employee* search(int empNumber) {
        Node* result = searchRec(root, empNumber);
        return (result != NULL) ? result->emp : NULL;
    }

    void deleteEmployee(int empNumber) {
        root = deleteRec(root, empNumber);
    }

    void inOrder() {
        cout << "In-order Traversal:\n";
        inOrderRec(root);
    }

    void preOrder() {
        cout << "Pre-order Traversal:\n";
        preOrderRec(root);
    }

    void postOrder() {
        cout << "Post-order Traversal:\n";
        postOrderRec(root);
    }
};


int main() {
    EmployeeBST tree;

    tree.insert(new Employee(1001, "Zafra", 50000));
    tree.insert(new Employee(1002, "Noor", 60000));
    tree.insert(new Employee(999, "Batool", 55000));

    tree.inOrder();
    tree.preOrder();
    tree.postOrder();

    Employee* emp = tree.search(1002);
    if (emp != NULL) {
        cout << "Found: ";
        emp->display();
    } else {
        cout << "Employee not found.\n";
    }

    tree.deleteEmployee(999);
    cout << "After deletion:\n";
    tree.inOrder();

    return 0;
}

