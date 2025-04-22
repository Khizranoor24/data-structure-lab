#include <iostream>
using namespace std;
struct Applicant {
    int id;
    float height;
    float weight;
    float eyesight;
    string status;
    Applicant* next;
    Applicant(int i, float h, float w, float e, string s) {
        id = i;
        height = h;
        weight = w;
        eyesight = e;
        status = s;
        next = NULL;
    }
};
class Queue {
    Applicant* front;
    Applicant* rear;
public:
    Queue() {
        front = rear = NULL;
    }
    void enqueue(int id, float height, float weight, float eyesight, string status) {
        Applicant* new_app = new Applicant(id, height, weight, eyesight, status);
        if (rear == NULL) {
            front = rear = new_app;
        } else {
            rear->next = new_app;
            rear = new_app;
        }
        cout << "Applicant " << id << " added.\n";
    }
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return;
        }
        Applicant* temp = front;
        cout << "Applicant " << temp->id << " gave the test and left the line.\n";
        front = front->next;
        delete temp;

        if (front == NULL)
            rear = NULL;
    }
    void removeSecond() {
        if (front == NULL || front->next == NULL) {
            cout << "Not enough applicants to remove second.\n";
            return;
        }
        Applicant* second = front->next;
        front->next = second->next;
        if (second == rear)
            rear = front;
        cout << "Applicant " << second->id << " left due to urgency.\n";
        delete second;
    }
    void display() {
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "\nCurrent Queue:\n";
        Applicant* temp = front;
        while (temp != NULL) {
            cout << "ID: " << temp->id
                 << ", Height: " << temp->height
                 << ", Weight: " << temp->weight
                 << ", Eyesight: " << temp->eyesight
                 << ", Status: " << temp->status << endl;
            temp = temp->next;
        }
        cout << "-----------------------\n";
    }
};
int main() {
    Queue q;
    q.enqueue(1, 5.8, 65, 6.0, "Pending");
    q.enqueue(2, 5.6, 60, 5.5, "Pending");
    q.enqueue(3, 5.9, 70, 6.2, "Pending");
    q.enqueue(4, 6.0, 75, 6.0, "Pending");
    q.enqueue(5, 5.7, 68, 5.8, "Pending");
    q.enqueue(6, 5.5, 64, 6.1, "Pending");
    q.enqueue(7, 6.1, 72, 6.3, "Pending");
    q.display();
    q.removeSecond();
    q.display();
    q.dequeue();
    q.display();
    return 0;
}

