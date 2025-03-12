#include <iostream>
#include <string>
using namespace std;

class Player {
public:
    string name;
    int score;
    Player* prev;
    Player* next;

    Player(string n, int s) {
        name = n;
        score = s;
        prev = NULL;
        next = NULL;
    }
};

class GolfTournament {
public:
    Player* head;

    GolfTournament() {
        head = NULL;
    }

    void addPlayer(string name, int score) {
        Player* newPlayer = new Player(name, score);
        if (!head || head->score > score) {
            newPlayer->next = head;
            if (head) head->prev = newPlayer;
            head = newPlayer;
        } else {
            Player* temp = head;
            while (temp->next && temp->next->score < score) {
                temp = temp->next;
            }
            newPlayer->next = temp->next;
            if (temp->next) temp->next->prev = newPlayer;
            temp->next = newPlayer;
            newPlayer->prev = temp;
        }
    }

    void deletePlayer(string name) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Player* temp = head;
        while (temp && temp->name != name) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Player not found.\n";
            return;
        }
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        if (temp == head) head = temp->next;
        delete temp;
        cout << "Player " << name << " deleted.\n";
    }

    void displayList() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Players (Sorted by Score):\n";
        Player* temp = head;
        while (temp) {
            cout << temp->name << " - " << temp->score << "\n";
            temp = temp->next;
        }
    }

    void displayLowestScore() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        cout << "Player with Lowest Score: " << head->name << " - " << head->score << "\n";
    }

    void displaySameScore(int score) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Player* temp = head;
        bool found = false;
        cout << "Players with score " << score << ":\n";
        while (temp) {
            if (temp->score == score) {
                cout << temp->name << "\n";
                found = true;
            }
            temp = temp->next;
        }
        if (!found) cout << "No players found with this score.\n";
    }

    void displayBackward(string name) {
        Player* temp = head;
        while (temp && temp->name != name) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Player not found.\n";
            return;
        }
        cout << "Players behind " << name << ":\n";
        while (temp->prev) {
            temp = temp->prev;
            cout << temp->name << " - " << temp->score << "\n";
        }
    }
};

int main() {
    GolfTournament gt;

    gt.addPlayer("Ali", 72);
    gt.addPlayer("fatma", 68);
    gt.addPlayer("sana", 74);
    gt.addPlayer("Danish", 68);
    gt.addPlayer("ilsa", 76);

    cout << "\n--- Initial List ---\n";
    gt.displayList();

    cout << "\n--- Lowest Score ---\n";
    gt.displayLowestScore();

    cout << "\n--- Players with Score 68 ---\n";
    gt.displaySameScore(68);

    cout << "\n--- Players Behind sana---\n";
    gt.displayBackward("sana");

    cout << "\n--- Deleting fatma ---\n";
    gt.deletePlayer("fatma");
    gt.displayList();

    return 0;
}
