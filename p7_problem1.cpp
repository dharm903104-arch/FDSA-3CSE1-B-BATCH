#include <iostream>
#include <string>

using namespace std;

const int MAX_CAPACITY = 5;

class TokenCounter {
private:
    string arr[MAX_CAPACITY];
    int front;
    int rear;
    int count;

public:
    TokenCounter() {
        front = -1;
        rear = -1;
        count = 0;
    }

    bool isFull() {
        return count == MAX_CAPACITY;
    }

    bool isEmpty() {
        return count == 0;
    }

    void join(string tokenID) {
        if(isFull())
        {
            cout << "Error: Counter is FULL! Cannot issue token '" << tokenID << "'.\n";
            return;
        }

        if(isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_CAPACITY;
        }

        arr[rear] = tokenID;
        count++;
        cout << "Visitor joined with token: " << tokenID << "\n";
    }

    void serve() {
        if(isEmpty())
        {
            cout << "Error: Counter is EMPTY! No visitor to serve.\n";
            return;
        }

        cout << "Served visitor with token: " << arr[front] << "\n";

        if(count == 1)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_CAPACITY;
        }
        count--;
    }

    void displayFront() {
        if(isEmpty())
        {
            cout << "Current Front Token: [None - Counter Empty]\n";
        }
        else
        {
            cout << "Current Front Token: " << arr[front] << "\n";
        }
    }
};

int main() {
    TokenCounter counter;
    int choice;
    string token;

    cout << "--- Government Office Token Counter (Circular Queue) ---\n";
    cout << "Counter capacity: " << MAX_CAPACITY << " tokens\n";

    while(true)
    {
        cout << "\n1. Visitor joins (issue token)\n2. Serve visitor\n3. Exit\nChoice: ";
        if(!(cin >> choice)) break;

        switch(choice){
            case 1:
                cout << "Enter Token ID/Name: ";
                cin >> token;
                counter.join(token);
                counter.displayFront();
                break;
            case 2:
                counter.serve();
                counter.displayFront();
                break;
            case 3:
                cout << "Closing token counter...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
