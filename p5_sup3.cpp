#include <iostream>
#include <string>

using namespace std;

struct StopNode {
    string stopName;
    StopNode* next;
    StopNode(string name)
    {
        stopName = name;
        next = nullptr;
    }
};

int main() {
    StopNode* head = nullptr;
    StopNode* tail = nullptr;
    int n;
    string name, startTarget;

    cout << "--- Circular Bus Route ---\n";
    cout << "How many stops are on the route? ";
    cin >> n;
    
    if(n <= 0)
    {
        cout << "No stops to traverse.\n";
        return 0;
    }

    cout << "Enter the names of the " << n << " stops in order:\n";
    for (int i = 0; i < n; i++) {
        cin >> name;
        StopNode* newNode = new StopNode(name);
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
    
    tail->next = head;

    cout << "Enter the stop name to start the route from: ";
    cin >> startTarget;

    StopNode* startNode = head;
    bool found = false;
    do{
        if(startNode->stopName == startTarget)
        {
            found = true;
            break;
        }
        startNode = startNode->next;
    }while(startNode != head);

    if(!found)
    {
        cout << "Error: Stop '" << startTarget << "' not found on the route.\n";
        return 0;
    }

    cout << "\nRoute starting from " << startTarget << ":\n";
    StopNode* curr = startNode;
    int count = 0;
    
    do{
        cout << curr->stopName << " -> ";
        count++;
        curr = curr->next;
    }while(curr != startNode);
    
    cout << "(back to " << startNode->stopName << ")\n";
    cout << "Total stops counted on traversal: " << count << "\n";

    return 0;
}