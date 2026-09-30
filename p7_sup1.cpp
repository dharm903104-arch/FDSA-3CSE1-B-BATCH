#include <iostream>
#include <string>

using namespace std;

struct QueueNode {
    string data;
    QueueNode* next;

    QueueNode(string val) {
        data = val;
        next = nullptr;
    }
};

class StringQueue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    StringQueue() {
        front = nullptr;
        rear = nullptr;
    }

    ~StringQueue() {
        while (front != nullptr) {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string val) {
        QueueNode* newNode = new QueueNode(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    string dequeue() {
        if (isEmpty()) {
            return "";
        }
        QueueNode* temp = front;
        string val = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return val;
    }
};

void generateBinaryNumbers(int n) {
    if (n <= 0) {
        cout << "Please enter a positive integer greater than 0.\n";
        return;
    }

    StringQueue q;
    q.enqueue("1");

    cout << "\nBinary representations from 1 to " << n << ":\n";
    for (int i = 1; i <= n; i++) {
        string current = q.dequeue();
        cout << i << " -> " << current << "\n";

        q.enqueue(current + "0");
        q.enqueue(current + "1");
    }
}

int main() {
    int n;

    cout << "--- Digital Display: Binary Number Generator (Queue) ---\n";
    cout << "Enter n: ";
    if (cin >> n) {
        generateBinaryNumbers(n);
    }

    return 0;
}
