#include <iostream>

using namespace std;

struct LoyaltyNode {
    int customerID;
    LoyaltyNode* next;
    LoyaltyNode(int id)
    {
        customerID = id;
        next = nullptr;
    }
};

int main() {
    LoyaltyNode* head = nullptr;
    LoyaltyNode* tail = nullptr;
    int n, id, target;

    cout << "--- Supermarket Loyalty System ---\n";
    cout << "Enter number of scanned customer IDs: ";
    cin >> n;
    
    if(n > 0) cout << "Enter the " << n << " IDs:\n";
    for(int i = 0; i < n; i++){
        cin >> id;
        LoyaltyNode* newNode = new LoyaltyNode(id);
        if(!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Enter target ID to completely remove: ";
    cin >> target;

    while(head != nullptr && head->customerID == target) 
    {
        LoyaltyNode* temp = head;
        head = head->next;
        delete temp;
    }

    LoyaltyNode* curr = head;
    while(curr != nullptr && curr->next != nullptr)
    {
        if(curr->next->customerID == target)
        {
            LoyaltyNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp; 
        }
        else
        {
            curr = curr->next;
        }
    }

    cout << "\nList after removing all occurrences of " << target << ":\n";
    if(!head)
    {
        cout << "[Empty]\n";
    }
    else
    {
        curr = head;
        while(curr)
        {
            cout << curr->customerID;
            if (curr->next) cout << " -> ";
            curr = curr->next;
        }
        cout << "\n";
    }

    return 0;
}