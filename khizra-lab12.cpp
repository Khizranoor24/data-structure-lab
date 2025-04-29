#include<iostream>
using namespace std;

struct Applicant
{
    int applicant_id;
    int height;
    int weight;
    int eyesight_vision;
    bool test_status;
    Applicant* next;
};

class Queue
{
private:
    Applicant* front;
    Applicant* rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    void enqueue(int id, int h, int w, int v, bool status)
    {
        Applicant* newApplicant = new Applicant;
        newApplicant->applicant_id = id;
        newApplicant->height = h;
        newApplicant->weight = w;
        newApplicant->eyesight_vision = v;
        newApplicant->test_status = status;
        newApplicant->next = NULL;

        if (rear == NULL)
        {
            front = rear = newApplicant;
            rear->next = front;  
        }
        else
        {
            rear->next = newApplicant;
            rear = newApplicant;
            rear->next = front;  
        }
    }

    void remove_second()
    {
        if (front == NULL || front->next == front)
        {
            cout << "Not enough applicants in line to remove second one." << endl;
            return;
        }

        Applicant* second = front->next;
        if (second == rear)
        {
           
            front->next = front;
            rear = front;
        }
        else
        {
            front->next = second->next;
        }

        delete second;
        rear->next = front;  
    }

    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        Applicant* temp = front;
        do
        {
            cout << "Applicant ID: " << temp->applicant_id
                << ", Height: " << temp->height
                << ", Weight: " << temp->weight
                << ", Eyesight Vision: " << temp->eyesight_vision
                << ", Test Status: " << (temp->test_status ? "Tested" : "Not Tested") << endl;
            temp = temp->next;
        } while (temp != front);
    }
};

int main()
{
    Queue q;
    q.enqueue(1, 170, 65, 20, false);
    q.enqueue(2, 160, 55, 15, false);
    q.enqueue(3, 175, 70, 10, false);
    q.enqueue(4, 180, 80, 25, false);
    q.enqueue(5, 165, 60, 18, false);
    q.enqueue(6, 170, 68, 22, false);
    q.enqueue(7, 155, 50, 30, false);

    cout << "Initial Queue:" << endl;
    q.display();

    q.remove_second();

    cout << "\nQueue after removing second applicant:" << endl;
    q.display();

    return 0;
}

