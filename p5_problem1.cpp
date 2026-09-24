#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string song;
    Node* prev;
    Node* next;
    Node(string s)
    {
        song = s;
        prev = nullptr;
        next = nullptr;
    }
};

class Playlist {
private:
    Node* head;
    Node* tail;
    int size;

public:
    Playlist()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void addFront(string song)
    {
        Node* newNode = new Node(song);
        if(!head)
        {
            head = tail = newNode;
        }
    else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
        display();
    }

    void addEnd(string song) 
{
        Node* newNode = new Node(song);
        if(!tail) 
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
        display();
    }

    void insertAfter(string targetSong, string newSong) {
        Node* curr = head;
        while(curr != nullptr && curr->song != targetSong)
        {
            curr = curr->next;
        }

        if(curr == nullptr)
        {
            cout << "Error: Song '" << targetSong << "' not found in the playlist.\n";
            display();
            return;
        }

        Node* newNode = new Node(newSong);
        newNode->next = curr->next;
        newNode->prev = curr;
        
        if(curr->next != nullptr)
        {
            curr->next->prev = newNode;
        }
        else
        {
            tail = newNode; 
        }
        curr->next = newNode;
        size++;
        display();
    }

    void removeFront() {
        if(!head)
        {
            cout << "Playlist is already empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr; 
        }
        cout << "Removed: " << temp->song << "\n";
        delete temp;
        size--;
        display();
    }

    void count() {
        cout << "Total songs in playlist: " << size << "\n";
    }

    void display() {
        if(!head)
        {
            cout << "Current Playlist: [Empty]\n\n";
            return;
        }
        cout << "Current Playlist: ";
        Node* curr = head;
        while(curr)
        {
            cout << "[" << curr->song << "]";
            if (curr->next) cout << " <-> ";
            curr = curr->next;
        }
        cout << "\n\n";
    }
};

int main() {
    Playlist p;
    int choice;
    string song, target;

    cout << "--- Music Player Playlist ---\n";
    while (true) {
        cout << "1. Add to beginning\n2. Add to end\n3. Insert after a song\n";
        cout << "4. Remove first song\n5. Count songs\n6. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                cout << "Enter song name: ";
                getline(cin, song);
                p.addFront(song);
                break;
            case 2:
                cout << "Enter song name: ";
                getline(cin, song);
                p.addEnd(song);
                break;
            case 3:
                cout << "Enter target song to insert after: ";
                getline(cin, target);
                cout << "Enter new song name: ";
                getline(cin, song);
                p.insertAfter(target, song);
                break;
            case 4:
                p.removeFront();
                break;
            case 5:
                p.count();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}