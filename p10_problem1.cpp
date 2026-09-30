#include <iostream>
#include <vector>

using namespace std;

const int LOT_SIZE = 10;

class ParkingLot {
private:
    int slots[LOT_SIZE];
    int occupiedCount;

public:
    ParkingLot() {
        for (int i = 0; i < LOT_SIZE; i++) {
            slots[i] = -1;
        }
        occupiedCount = 0;
    }

    void parkVehicle(int regNumber) {
        if (occupiedCount >= LOT_SIZE) {
            cout << "Error: Parking lot is completely FULL! Cannot park vehicle " << regNumber << ".\n";
            return;
        }

        int initialSlot = regNumber % LOT_SIZE;
        int currentSlot = initialSlot;
        int probes = 0;

        while (probes < LOT_SIZE) {
            if (slots[currentSlot] == -1) {
                slots[currentSlot] = regNumber;
                occupiedCount++;
                if (probes == 0) {
                    cout << "Vehicle " << regNumber << " parked in preferred slot " << currentSlot << ".\n";
                } else {
                    cout << "Collision at slot " << initialSlot << "! Vehicle " << regNumber
                         << " probed and parked in slot " << currentSlot << " after " << probes << " shifts.\n";
                }
                return;
            }

            currentSlot = (currentSlot + 1) % LOT_SIZE;
            probes++;
        }

        cout << "Error: No free slot found for vehicle " << regNumber << ".\n";
    }

    void displayLot() {
        cout << "\n--- Final State of Parking Lot Slots ---\n";
        cout << "Slot # | Vehicle Registration\n";
        cout << "-----------------------------\n";
        for (int i = 0; i < LOT_SIZE; i++) {
            cout << "  " << i << "    | ";
            if (slots[i] == -1) {
                cout << "[ EMPTY ]\n";
            } else {
                cout << slots[i] << "\n";
            }
        }
        cout << "-----------------------------\n";
        cout << "Occupied: " << occupiedCount << " / " << LOT_SIZE << " slots\n";
    }
};

int main() {
    ParkingLot lot;
    int choice;

    cout << "--- Parking Lot Assignment System (Linear Probing) ---\n";
    cout << "1. Run with sample vehicles (colliding last digits)\n";
    cout << "2. Enter custom vehicle registrations\n";
    cout << "Choice: ";

    if (!(cin >> choice)) return 0;

    if (choice == 1) {

        vector<int> sampleVehicles = {104, 234, 554, 789, 990, 312, 415};
        cout << "\nParking sample vehicles: 104, 234, 554, 789, 990, 312, 415\n\n";
        for (int v : sampleVehicles) {
            lot.parkVehicle(v);
        }
        lot.displayLot();
    } else {
        int n, reg;
        cout << "Enter number of vehicles: ";
        cin >> n;
        cout << "Enter " << n << " registration numbers (separated by space): ";
        for (int i = 0; i < n; i++) {
            cin >> reg;
            lot.parkVehicle(reg);
        }
        lot.displayLot();
    }

    return 0;
}
