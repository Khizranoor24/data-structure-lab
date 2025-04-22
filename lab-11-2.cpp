#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;
int road[MAX], road_front = 0, road_rear = 0;
int garage[MAX], garage_top = -1;

void on_road(int truck_id) {
    road[road_rear++] = truck_id;
}

void enter_garage(int truck_id) {
    if (road[road_front] != truck_id) {
        cout << "Error: " << truck_id << " NO. Vehicle cannot enter into garage." << endl;
        return;
    }
    bool found = false;
    int temp[MAX], temp_size = 0;

    for (int i = road_front; i < road_rear; i++) {
        if (road[i] == truck_id && !found) {
            found = true;
            garage[++garage_top] = truck_id;
        } else {
            temp[temp_size++] = road[i];
        }
    }

    road_front = 0;
    road_rear = 0;
    for (int i = 0; i < temp_size; i++) {
        road[road_rear++] = temp[i];
    }
}

void exit_garage(int truck_id) {
    if (garage_top == -1 || garage[garage_top] != truck_id) {
        cout << "Error: " << truck_id << " No. Vehicle cannot exit garage." << endl;
    } else {
        garage_top--;
        cout << truck_id << " No. vehicle leaving garage" << endl;
    }
}

void show_trucks(string location) {
    if (location == "road") {
        cout << "Road Vehicle: ";
        for (int i = road_front; i < road_rear; i++) {
            cout << road[i];
            if (i < road_rear - 1) cout << "_";
        }
        if (road_front == road_rear) cout << "Empty";
        cout << endl;
    } else if (location == "garage") {
        cout << "Garage Vehicle: ";
        if (garage_top == -1) {
            cout << "Empty";
        } else {
            for (int i = garage_top; i >= 0; i--) {
                cout << garage[i];
                if (i > 0) cout << "_";
            }
        }
        cout << endl;
    }
}

int main() {
    on_road(2);
    on_road(5);
    on_road(10);
    on_road(9);
    on_road(22);
    show_trucks("road");
    show_trucks("garage");
    enter_garage(2);
    show_trucks("road");
    show_trucks("garage");
    enter_garage(10);
    enter_garage(5);
    exit_garage(2);
    exit_garage(5);
    show_trucks("garage");

    return 0;
}
