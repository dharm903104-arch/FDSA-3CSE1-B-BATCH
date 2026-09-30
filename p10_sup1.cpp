#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int TABLE_SIZE = 10;

struct StudentRecord {
    int id;
    int score;
    StudentRecord* next;

    StudentRecord(int studentId, int studentScore) {
        id = studentId;
        score = studentScore;
        next = nullptr;
    }
};

class LinearProbingTable {
private:
    int ids[TABLE_SIZE];
    int scores[TABLE_SIZE];
    bool occupied[TABLE_SIZE];
    int count;

public:
    LinearProbingTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            occupied[i] = false;
        }
        count = 0;
    }

    void insert(int id, int score) {
        if (count >= TABLE_SIZE) {
            cout << "Linear Probing Table is FULL! Cannot insert ID " << id << ".\n";
            return;
        }

        int index = id % TABLE_SIZE;
        int probes = 0;

        while (probes < TABLE_SIZE) {
            if (!occupied[index]) {
                ids[index] = id;
                scores[index] = score;
                occupied[index] = true;
                count++;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            probes++;
        }
    }

    int lookup(int id, int& probesTaken) {
        int index = id % TABLE_SIZE;
        probesTaken = 0;

        while (probesTaken < TABLE_SIZE) {
            if (!occupied[index]) {
                return -1;
            }
            probesTaken++;
            if (ids[index] == id) {
                return scores[index];
            }
            index = (index + 1) % TABLE_SIZE;
        }
        return -1;
    }

    void display() {
        cout << "\n[Mode 1: Linear Probing Table State]\n";
        cout << "Slot # | Student ID | Score\n";
        cout << "---------------------------\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "  " << i << "    | ";
            if (!occupied[i]) {
                cout << "[ EMPTY ]\n";
            } else {
                cout << ids[i] << "        | " << scores[i] << "\n";
            }
        }
        cout << "---------------------------\n";
    }
};

class SeparateChainingTable {
private:
    StudentRecord* buckets[TABLE_SIZE];

public:
    SeparateChainingTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            buckets[i] = nullptr;
        }
    }

    ~SeparateChainingTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            StudentRecord* curr = buckets[i];
            while (curr != nullptr) {
                StudentRecord* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
    }

    void insert(int id, int score) {
        int index = id % TABLE_SIZE;
        StudentRecord* newRecord = new StudentRecord(id, score);
        newRecord->next = buckets[index];
        buckets[index] = newRecord;
    }

    int lookup(int id, int& nodesChecked) {
        int index = id % TABLE_SIZE;
        nodesChecked = 0;
        StudentRecord* curr = buckets[index];

        while (curr != nullptr) {
            nodesChecked++;
            if (curr->id == id) {
                return curr->score;
            }
            curr = curr->next;
        }
        return -1;
    }

    void display() {
        cout << "\n[Mode 2: Separate Chaining Table State]\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Slot " << i << ": ";
            StudentRecord* curr = buckets[i];
            if (curr == nullptr) {
                cout << "[ EMPTY ]\n";
            } else {
                while (curr != nullptr) {
                    cout << "(ID: " << curr->id << ", Score: " << curr->score << ") -> ";
                    curr = curr->next;
                }
                cout << "NULL\n";
            }
        }
        cout << "--------------------------------------\n";
    }
};

int main() {
    cout << "--- Flexible University Student Record System ---\n";
    cout << "1. Run demo with sample student records in both modes\n";
    cout << "2. Interactive department mode selection & input\n";
    cout << "Choice: ";

    int choice;
    if (!(cin >> choice)) return 0;

    if (choice == 1) {
        vector<pair<int, int>> sampleData = {
            {101, 88}, {201, 92}, {301, 75}, {104, 85},
            {204, 90}, {109, 95}, {309, 82}, {107, 79}
        };

        LinearProbingTable lp;
        SeparateChainingTable sc;

        cout << "\nInserting 8 student records: (101,88), (201,92), (301,75), (104,85), (204,90), (109,95), (309,82), (107,79)\n";
        for (const auto& rec : sampleData) {
            lp.insert(rec.first, rec.second);
            sc.insert(rec.first, rec.second);
        }

        lp.display();
        sc.display();

        int searchId = 301;
        int probesLP = 0, nodesSC = 0;
        int scoreLP = lp.lookup(searchId, probesLP);
        int scoreSC = sc.lookup(searchId, nodesSC);

        cout << "\n[Lookup Comparison for ID " << searchId << "]:\n";
        cout << "- Linear Probing: Score = " << scoreLP << " (Probes inspected: " << probesLP << ")\n";
        cout << "- Separate Chaining: Score = " << scoreSC << " (Chain nodes checked: " << nodesSC << ")\n";
    } else {
        int mode;
        cout << "\nSelect Department Mode:\n1. Linear Probing (few students)\n2. Separate Chaining (high density)\nChoice: ";
        cin >> mode;

        int n;
        cout << "Enter number of student records: ";
        cin >> n;

        if (mode == 1) {
            LinearProbingTable lp;
            cout << "Enter " << n << " records (ID Score pairs):\n";
            for (int i = 0; i < n; i++) {
                int id, score;
                cin >> id >> score;
                lp.insert(id, score);
            }
            lp.display();
        } else {
            SeparateChainingTable sc;
            cout << "Enter " << n << " records (ID Score pairs):\n";
            for (int i = 0; i < n; i++) {
                int id, score;
                cin >> id >> score;
                sc.insert(id, score);
            }
            sc.display();
        }
    }

    return 0;
}
