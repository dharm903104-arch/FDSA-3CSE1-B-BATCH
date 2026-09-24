#include <iostream>
#include <string>

using namespace std;

struct SNode {
    string name;
    SNode* next;
    SNode(string s)
    {
        name = s;
        next = nullptr;
    }
};

class SinglyCircular {
private:
    SNode* head;
public:
    SinglyCircular()
    {
        head = nullptr;
    }

    void join(int pos, string name)
    {
        SNode* newNode = new SNode(name);
        if(!head)
        {
            head = newNode;
            head->next = head;
            return;
        }
        
        if(pos == 1)
        {
            SNode* temp = head;
            while (temp->next != head) { temp = temp->next; }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        else
        {
            SNode* temp = head;
            for (int i = 1; i < pos - 1 && temp->next != head; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void leave(string name) {
        if (!head) return;

        SNode* curr = head;
        SNode* prev = nullptr;

        while(curr->name != name)
        {
            if(curr->next == head)
            {
                cout << "Student " << name << " not found in Singly Circle.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        if(curr->next == head && prev == nullptr)
        {
            head = nullptr;
            delete curr;
            return;
        }

        if(curr == head)
        {
            SNode* temp = head;
            while (temp->next != head) { temp = temp->next; }
            head = head->next;
            temp->next = head;
            delete curr;
        } 
        else
        {
            prev->next = curr->next;
            delete curr;
        }
    }

    void display() {
        cout << "Singly Circular: ";
        if(!head)
        {
            cout << "[Empty]\n";
            return;
        }
        SNode* temp = head;
        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        }while(temp != head);
        cout << "(back to " << head->name << ")\n";
    }
};


struct DNode {
    string name;
    DNode* prev;
    DNode* next;
    
    DNode(string s)
    {
        name = s;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyCircular {
private:
    DNode* head;
public:
    DoublyCircular()
    {
        head = nullptr;
    }

    void join(int pos, string name)
    {
        DNode* newNode = new DNode(name);
        if(!head)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        if(pos == 1)
        {
            DNode* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            DNode* temp = head;
            for (int i = 1; i < pos - 1 && temp->next != head; i++) {
                temp = temp->next;
            }
            DNode* nextNode = temp->next;
            
            newNode->next = nextNode;
            newNode->prev = temp;
            temp->next = newNode;
            nextNode->prev = newNode;
        }
    }

    void leave(string name) {
        if(!head) return;

        DNode* curr = head;
        while(curr->name != name)
        {
            curr = curr->next;
            if(curr == head)
            {
                cout << "Student " << name << " not found in Doubly Circle.\n";
                return;
            }
        }

        if(curr->next == head)
        {
            head = nullptr;
            delete curr;
            return;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        if(curr == head)
        {
            head = curr->next;
        }
        delete curr;
    }

    void display() {
        cout << "Doubly Circular: ";
        if(!head)
        {
            cout << "[Empty]\n";
            return;
        }
        DNode* temp = head;
        do{
            cout << temp->name << " <-> ";
            temp = temp->next;
        } while(temp != head);
        cout << "(back to " << head->name << ")\n";
    }
};

int main() {
    SinglyCircular sc;
    DoublyCircular dc;
    int choice, pos;
    string name;

    cout << "--- Passing Game Circle ---\n";
    while(true)
    {
        cout << "\n1. Student Joins\n2. Student Leaves\n3. Exit\nChoice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter student name: ";
                cin >> name;
                cout << "Enter position to join (1 for front, 2 for second, etc.): ";
                cin >> pos;
                sc.join(pos, name);
                dc.join(pos, name);
                cout << "\nCircle updated:\n";
                sc.display();
                dc.display();
                break;
            case 2:
                cout << "Enter student name who is leaving: ";
                cin >> name;
                sc.leave(name);
                dc.leave(name);
                cout << "\nCircle updated:\n";
                sc.display();
                dc.display();
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}