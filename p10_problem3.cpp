#include <iostream>
#include <vector>

using namespace std;

const int TABLE_SIZE = 10;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class StudentStorageSystem {
private:
    int slots[TABLE_SIZE];
    int count;

public:
    StudentStorageSystem() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            slots[i] = -1;
        }
        count = 0;
    }

    int hash1(int id) {
        return id % TABLE_SIZE;
    }

    int hash2(int id) {
        int step = 1 + (id % 7);

        while (gcd(step, TABLE_SIZE) != 1) {
            step++;
        }
        return step;
    }

    void assignSlot(int studentID) {
        if (count >= TABLE_SIZE) {
            cout << "Error: Storage is completely FULL! Cannot assign ID " << studentID << ".\n";
            return;
        }

        int initialSlot = hash1(studentID);
        int jumpSize = hash2(studentID);
        int currentSlot = initialSlot;
        int probes = 0;

        while (probes < TABLE_SIZE) {
            if (slots[currentSlot] == -1) {
                slots[currentSlot] = studentID;
                count++;
                if (probes == 0) {
                    cout << "Student ID " << studentID << " assigned to initial slot " << currentSlot << ".\n";
                } else {
                    cout << "Collision at initial slot " << initialSlot << "! ID " << studentID
                         << " jumped by " << jumpSize << " slots (probe " << probes << ") -> assigned to slot "
                         << currentSlot << ".\n";
                }
                return;
            }

            currentSlot = (currentSlot + jumpSize) % TABLE_SIZE;
            probes++;
        }

        cout << "Error: No free slot found for Student ID " << studentID << " after probing.\n";
    }

    void displaySlots() {
        cout << "\n--- Final State of Student Storage Slots (Double Hashing) ---\n";
        cout << "Slot # | Assigned Student ID\n";
        cout << "----------------------------\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "  " << i << "    | ";
            if (slots[i] == -1) {
                cout << "[ EMPTY ]\n";
            } else {
                cout << slots[i] << "\n";
            }
        }
        cout << "----------------------------\n";
        cout << "Occupied: " << count << " / " << TABLE_SIZE << " slots\n";
    }
};

int main() {
    StudentStorageSystem storage;
    int choice;

    cout << "--- University Student Storage System (Double Hashing) ---\n";
    cout << "1. Run with sample student IDs (demonstrating dynamic jumps)\n";
    cout << "2. Enter custom student IDs\n";
    cout << "Choice: ";

    if (!(cin >> choice)) return 0;

    if (choice == 1) {

        vector<int> sampleIDs = {104, 224, 305, 415, 512, 608, 718};
        cout << "\nAssigning sample student IDs: 104, 224, 305, 415, 512, 608, 718\n\n";
        for (int id : sampleIDs) {
            storage.assignSlot(id);
        }
        storage.displaySlots();
    } else {
        int n, id;
        cout << "Enter number of student IDs: ";
        cin >> n;
        cout << "Enter " << n << " student IDs (separated by space): ";
        for (int i = 0; i < n; i++) {
            cin >> id;
            storage.assignSlot(id);
        }
        storage.displaySlots();
    }

    return 0;
}
