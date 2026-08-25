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

void swapPairs(Node* head) {
    Node* curr = head;
    while(curr && curr->next) {
        int temp = curr->data;
        curr->data = curr->next->data;
        curr->next->data = temp;
        curr = curr->next->next;
    }
}

void printList(Node* head) {
    while(head) { cout<<head->data<<" "; head=head->next; }
    cout<<"\n";
}

int main() {
    Node* head = NULL;
    for(int i=1;i<=5;i++) addBack(head,i);

    swapPairs(head);
    printList(head);
}
