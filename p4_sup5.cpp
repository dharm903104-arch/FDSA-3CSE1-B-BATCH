#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char d): data(d), next(NULL) {}
};

void addBack(Node*& head, char value) {
    Node* newNode = new Node(value);
    if(!head) { head = newNode; return; }
    Node* curr = head;
    while(curr->next) curr = curr->next;
    curr->next = newNode;
}

bool isPalindrome(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* prev = NULL;
    Node* curr = slow;
    while(curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    Node* left = head;
    Node* right = prev;
    while(right) {
        if(left->data != right->data) return false;
        left = left->next;
        right = right->next;
    }
    return true;
}

int main() {
    Node* head = NULL;
    string s = "radar";
    for(char c: s) addBack(head,c);

    cout<<(isPalindrome(head)?"Yes":"No")<<"\n";
}
