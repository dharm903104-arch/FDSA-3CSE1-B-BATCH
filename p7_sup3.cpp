#include <iostream>
#include <string>

using namespace std;

struct StackNode {
    string ticket;
    StackNode* next;

    StackNode(string t) {
        ticket = t;
        next = nullptr;
    }
};

class SimpleStack {
private:
    StackNode* topNode;

public:
    SimpleStack() {
        topNode = nullptr;
    }

    ~SimpleStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    void push(string t) {
        StackNode* newNode = new StackNode(t);
        newNode->next = topNode;
        topNode = newNode;
    }

    string pop() {
        if (isEmpty()) return "";
        StackNode* temp = topNode;
        string t = temp->ticket;
        topNode = topNode->next;
        delete temp;
        return t;
    }

    string peek() {
        return isEmpty() ? "" : topNode->ticket;
    }
};

class TicketBoothQueue {
private:
    SimpleStack s1;
    SimpleStack s2;

    void transferIfNecessary() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }
    }

public:
    void addTicket(string ticket) {
        s1.push(ticket);
        cout << "Added ticket to booth: " << ticket << "\n";
    }

    void issueTicket() {
        transferIfNecessary();

        if (s2.isEmpty()) {
            cout << "Error: No tickets available! Booth is empty.\n";
            return;
        }

        string issued = s2.pop();
        cout << "Issued ticket (FIFO): " << issued << "\n";
    }

    void displayNextToIssue() {
        transferIfNecessary();

        if (s2.isEmpty()) {
            cout << "Next Ticket to Issue: [None - Booth Empty]\n";
        } else {
            cout << "Next Ticket to Issue: " << s2.peek() << "\n";
        }
    }
};

int main() {
    TicketBoothQueue booth;
    int choice;
    string ticket;

    cout << "--- Ticketing Booth (Queue using Two Stacks) ---\n";

    while (true) {
        cout << "\n1. Add ticket (intake)\n2. Issue ticket (oldest first)\n3. Exit\nChoice: ";
        if (!(cin >> choice)) break;

        switch (choice) {
            case 1:
                cout << "Enter Ticket ID/Number: ";
                cin >> ticket;
                booth.addTicket(ticket);
                booth.displayNextToIssue();
                break;
            case 2:
                booth.issueTicket();
                booth.displayNextToIssue();
                break;
            case 3:
                cout << "Closing ticketing booth...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
