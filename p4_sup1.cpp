#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d): data(d), next(NULL) {}
};

void addBack(Node*& head, int value) {
    Node* newNode = new Node(value);
    if(!head) { head = newNode; return; }
    Node* curr = head;
    while(curr->next) curr = curr->next;
    curr->next = newNode;
}

void removeKFromRear(Node*& head, int k) {
    Node* fast = head;
    for(int i=0; i<k; i++) {
        if(!fast) return;
        fast = fast->next;
    }
    if(!fast) { 
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* slow = head;
    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    Node* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
}

void printList(Node* head) {
    while(head) { cout<<head->data<<" "; head=head->next; }
    cout<<"\n";
}

int main() {
    Node* head = NULL;
    for(int i=1;i<=5;i++) addBack(head,i);

    int k=2;
    removeKFromRear(head,k);
    printList(head);
}
