#include <iostream>
using namespace std;

struct Node {
    int token;
    Node* next;
    Node(int val) : token(val), next(nullptr) {}
};

class HospitalQueue {
    Node* head;
    Node* tail;

public:
    HospitalQueue() : head(nullptr), tail(nullptr) {}

    void pushFront(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) tail = head; 
        printForward();
    }

    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (tail) {
            tail->next = newNode;
            tail = newNode;
        } else {
            head = tail = newNode;
        }
        printForward();
    }

    void insertAt(int val, int pos) {
        if (pos <= 1) {
            pushFront(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        int count = 1;
        while (temp && count < pos - 1) {
            temp = temp->next;
            count++;
        }
        if (!temp) {
           
            pushBack(val);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == nullptr) tail = newNode; 
        printForward();
    }

 
    void deleteByValue(int val) {
        if (!head) return;
        if (head->token == val) {
            Node* del = head;
            head = head->next;
            delete del;
            if (!head) tail = nullptr;
            printForward();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->token != val) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* del = temp->next;
            temp->next = del->next;
            if (del == tail) tail = temp;
            delete del;
        }
        printForward();
    }


    void printForward() {
        cout << "Queue (front -> back): ";
        Node* temp = head;
        while (temp) {
            cout << temp->token << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printReverse(Node* node) {
        if (!node) return;
        printReverse(node->next);
        cout << node->token << " ";
    }

    void auditReverse() {
        cout << "Queue (back -> front): ";
        printReverse(head);
        cout << endl;
    }
};

int main() {
    HospitalQueue q;

   
    q.pushBack(101);       
    q.pushFront(201);      
    q.insertAt(301, 2);    
    q.insertAt(401, 10);   
    q.deleteByValue(301); 
    q.auditReverse();      

    return 0;
}
