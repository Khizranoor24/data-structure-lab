#include <iostream>
#include <string>
using namespace std;

struct Player {
    string name;
    int score;
    Player* next;
    Player* prev;

    Player(string n, int s) {
        name = n;
        score = s;
        next = NULL;
        prev = NULL;
    }
};

class PlayerList {
private:
    Player* head;

public:
    PlayerList() {
        head = NULL;
    }

    void addPlayer(string name, int score) {
        Player* newPlayer = new Player(name, score);

        if (head == NULL) {
            head = newPlayer;
            return;
        }

        Player* current = head;

        while (current != NULL && current->score < score) {
            current = current->next;
        }

        if (current == NULL) {
            Player* last = head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newPlayer;
            newPlayer->prev = last;
        } else {
            if (current == head) {

                newPlayer->next = head;
                head->prev = newPlayer;
                head = newPlayer;
            } else {

                newPlayer->next = current;
                newPlayer->prev = current->prev;
                current->prev->next = newPlayer;
                current->prev = newPlayer;
            }
        }
    }

    void displayAllPlayers() {
        if (head == NULL) {
            cout << "No players in the list." << endl;
            return;
        }
        Player* current = head;
        while (current != NULL) {
            cout << "Player: " << current->name << " | Score: " << current->score << endl;
            current = current->next;
        }
    }

    void displayLowestScore() {
        if (head == NULL) {
            cout << "No players in the list." << endl;
            return;
        }
        cout << "Player with the lowest score: " << head->name << " | Score: " << head->score << endl;
    }

    void displaySameScorePlayers(int score) {
        if (head == NULL) {
            cout << "No players in the list." << endl;
            return;
        }

        bool found = false;
        Player* current = head;
        while (current != NULL) {
            if (current->score == score) {
                cout << "Player: " << current->name << " | Score: " << current->score << endl;
                found = true;
            }
            current = current->next;
        }

        if (!found) {
            cout << "No players found with score " << score << endl;
        }
    }

    void displayBackwardFromPlayer(string name) {
        if (head == NULL) {
            cout << "No players in the list." << endl;
            return;
        }

        Player* current = head;
        while (current != NULL && current->name != name) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Player not found." << endl;
            return;
        }

        cout << "Players backward from " << name << " are:" << endl;
        while (current != NULL) {
            cout << "Player: " << current->name << " | Score: " << current->score << endl;
            current = current->prev;
        }
    }
};

int main() {
    PlayerList playerList;

    int choice;
    string name;
    int score;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Player" << endl;
        cout << "2. Display All Players" << endl;
        cout << "3. Display Player with Lowest Score" << endl;
        cout << "4. Display Players with Same Score" << endl;
        cout << "5. Display Backward from a Player" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter player's name: ";
                cin >> name;
                cout << "Enter player's score: ";
                cin >> score;
                playerList.addPlayer(name, score);
                break;

            case 2:
                playerList.displayAllPlayers();
                break;

            case 3:
                playerList.displayLowestScore();
                break;

            case 4:
                cout << "Enter the score to search for players: ";
                cin >> score;
                playerList.displaySameScorePlayers(score);
                break;

            case 5:
                cout << "Enter player's name to display backward: ";
                cin >> name;
                playerList.displayBackwardFromPlayer(name);
                break;

            case 6:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

