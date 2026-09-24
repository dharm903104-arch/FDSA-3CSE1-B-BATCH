#include <iostream>
#include <string>

using namespace std;

const int MAX_TRAYS = 5;

class TrayCounter {
private:
    string stack[MAX_TRAYS];
    int top;

public:
    TrayCounter() {
        top = -1;
    }

    void placeTray(string trayID) {
        if(top >= MAX_TRAYS - 1)
        {
            cout << "Error: Counter is FULL! Cannot place tray '" << trayID << "'.\n";
            return;
        }
        top++;
        stack[top] = trayID;
        cout << "Placed tray: " << trayID << "\n";
    }

    void takeTray() {
        if(top == -1)
        {
            cout << "Error: Counter is EMPTY! No tray to take.\n";
            return;
        }
        cout << "Customer took tray: " << stack[top] << "\n";
        top--;
    }

    void displayTop() {
        if(top == -1)
        {
            cout << "Current Top Tray: [None - Counter Empty]\n";
        }
        else
        {
            cout << "Current Top Tray: " << stack[top] << "\n";
        }
    }
};

int main() {
    TrayCounter cafeteria;
    int choice;
    string tray;

    cout << "--- Cafeteria Tray Stack ---\n";
    cout << "Counter capacity: " << MAX_TRAYS << " trays\n";

    while(true){
        cout << "\n1. Place clean tray\n2. Customer takes tray\n3. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter tray ID/Color: ";
                cin >> tray;
                cafeteria.placeTray(tray);
                cafeteria.displayTop();
                break;
            case 2:
                cafeteria.takeTray();
                cafeteria.displayTop();
                break;
            case 3:
                cout << "Closing cafeteria...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}