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

int findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

int main() {
    Node* head = NULL;
    for(int i=10;i<=60;i+=10) addBack(head,i);

    cout<<"Middle: "<<findMiddle(head)<<"\n";
}
