#include <iostream>
#include <string>

using namespace std;

struct Node {
    string dish;
    Node* next;

    Node(string d) {
        dish = d;
        next = nullptr;
    }
};

class SimpleQueue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    SimpleQueue() {
        front = rear = nullptr;
        count = 0;
    }

    ~SimpleQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    int size() {
        return count;
    }

    void enqueue(string d) {
        Node* newNode = new Node(d);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    string dequeue() {
        if (isEmpty()) return "";
        Node* temp = front;
        string d = temp->dish;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        count--;
        return d;
    }

    string peek() {
        return isEmpty() ? "" : front->dish;
    }
};

class KitchenStack {
private:
    SimpleQueue counter1;
    SimpleQueue counter2;

public:

    void addDish(string dish) {
        counter2.enqueue(dish);

        while (!counter1.isEmpty()) {
            counter2.enqueue(counter1.dequeue());
        }

        while (!counter2.isEmpty()) {
            counter1.enqueue(counter2.dequeue());
        }

        cout << "Prepared & added dish: " << dish << "\n";
    }

    void serveDish() {
        if (counter1.isEmpty()) {
            cout << "Error: No dishes to serve! Kitchen counter is empty.\n";
            return;
        }

        string served = counter1.dequeue();
        cout << "Plated and served dish (LIFO): " << served << "\n";
    }

    void displayNextToServe() {
        if (counter1.isEmpty()) {
            cout << "Next Dish to Serve: [None]\n";
        } else {
            cout << "Next Dish to Serve: " << counter1.peek() << "\n";
        }
    }
};

int main() {
    KitchenStack kitchen;
    int choice;
    string dish;

    cout << "--- Kitchen Serving Counters (Stack using Two Queues) ---\n";

    while (true) {
        cout << "\n1. Add dish (newly prepared)\n2. Serve dish (most recent first)\n3. Exit\nChoice: ";
        if (!(cin >> choice)) break;

        switch (choice) {
            case 1:
                cout << "Enter Dish Name: ";
                cin >> dish;
                kitchen.addDish(dish);
                kitchen.displayNextToServe();
                break;
            case 2:
                kitchen.serveDish();
                kitchen.displayNextToServe();
                break;
            case 3:
                cout << "Closing kitchen service...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
