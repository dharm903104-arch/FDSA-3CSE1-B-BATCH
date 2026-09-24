#include <iostream>

using namespace std;

struct WardNode {
    int id;
    WardNode* next;
    WardNode(int val)
    {
        id = val;
        next = nullptr;
    }
};

void insertTail(WardNode*& head, WardNode*& tail, int id) {
    WardNode* newNode = new WardNode(id);
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

void printWard(WardNode* head) {
    if(!head)
    {
        cout << "[Empty]\n";
        return;
    }
    while(head)
    {
        cout << head->id;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    WardNode *list1Head = nullptr, *list1Tail = nullptr;
    WardNode *list2Head = nullptr, *list2Tail = nullptr;
    int n1, n2, val;

    cout << "--- Hospital Ward Merge ---\n";
    
    cout << "Enter number of patients in Ward 1: ";
    cin >> n1;
    if(n1 > 0) cout << "Enter " << n1 << " IDs in sorted order:\n";
    for (int i = 0; i < n1; i++) {
        cin >> val;
        insertTail(list1Head, list1Tail, val);
    }

    cout << "Enter number of patients in Ward 2: ";
    cin >> n2;
    if(n2 > 0) cout << "Enter " << n2 << " IDs in sorted order:\n";
    for (int i = 0; i < n2; i++) {
        cin >> val;
        insertTail(list2Head, list2Tail, val);
    }

    WardNode* mergedHead = nullptr;
    WardNode* mergedTail = nullptr;
    WardNode* p1 = list1Head;
    WardNode* p2 = list2Head;

    if(!p1) mergedHead = p2;
    else if(!p2) mergedHead = p1;
    else
    {
        if (p1->id <= p2->id)
        {
            mergedHead = mergedTail = p1;
            p1 = p1->next;
        }
        else 
        {
            mergedHead = mergedTail = p2;
            p2 = p2->next;
        }
        
        while(p1 && p2)
        {
            if(p1->id <= p2->id)
            {
                mergedTail->next = p1;
                mergedTail = p1;
                p1 = p1->next;
            }
            else
            {
                mergedTail->next = p2;
                mergedTail = p2;
                p2 = p2->next;
            }
        }
        
        if(p1) mergedTail->next = p1;
        if(p2) mergedTail->next = p2;
    }

    cout << "\nMerged Unified List: ";
    printWard(mergedHead);

    return 0;
}