#include <iostream>
#include <string>

using namespace std;

struct PatientNode {
    string name;
    PatientNode* next;

    PatientNode(string n) {
        name = n;
        next = nullptr;
    }
};

class EmergencyWard {
private:
    PatientNode* front;
    PatientNode* rear;

public:
    EmergencyWard() {
        front = nullptr;
        rear = nullptr;
    }

    ~EmergencyWard() {
        while (front != nullptr) {
            PatientNode* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void arrive(string patientName) {
        PatientNode* newPatient = new PatientNode(patientName);
        if (isEmpty()) {
            front = rear = newPatient;
        } else {
            rear->next = newPatient;
            rear = newPatient;
        }
        cout << "Patient arrived: " << patientName << "\n";
    }

    void attend() {
        if (isEmpty()) {
            cout << "Error: No patients waiting in the emergency ward!\n";
            return;
        }

        PatientNode* temp = front;
        cout << "Doctor attending to patient: " << temp->name << "\n";
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    void displayFront() {
        if (isEmpty()) {
            cout << "Current Front Patient: [None - Ward is Empty]\n";
        } else {
            cout << "Current Front Patient: " << front->name << "\n";
        }
    }
};

int main() {
    EmergencyWard ward;
    int choice;
    string patient;

    cout << "--- Hospital Emergency Ward Queue (Linked List) ---\n";

    while (true) {
        cout << "\n1. Patient arrives\n2. Doctor attends to patient\n3. Exit\nChoice: ";
        if (!(cin >> choice)) break;

        switch (choice) {
            case 1:
                cout << "Enter Patient Name: ";
                cin >> patient;
                ward.arrive(patient);
                ward.displayFront();
                break;
            case 2:
                ward.attend();
                ward.displayFront();
                break;
            case 3:
                cout << "Closing emergency ward...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
