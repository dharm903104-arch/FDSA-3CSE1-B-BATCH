#include <iostream>
#include <string>

using namespace std;

struct PageNode {
    string url;
    PageNode* next;
    
    PageNode(string u)
    {
        url = u;
        next = nullptr;
    }
};

class BrowserHistory {
private:
    PageNode* top;

public:
    BrowserHistory() {
        top = nullptr; 
    }

    void visit(string url) {
        PageNode* newPage = new PageNode(url);
        newPage->next = top;
        top = newPage;
        cout << "Visited: " << url << "\n";
    }

    void back() {
        if(top == nullptr)
        {
            cout << "Error: No history left! Cannot go back further.\n";
            return;
        }
        
        PageNode* temp = top;
        top = top->next; 
        
        cout << "Pressed back, leaving: " << temp->url << "\n";
        delete temp;
    }

    void displayCurrent() {
        if(top == nullptr)
        {
            cout << "Current Page: [Blank New Tab]\n";
        } 
        else
        {
            cout << "Current Page: " << top->url << "\n";
        }
    }
};

int main() {
    BrowserHistory browser;
    int choice;
    string url;

    cout << "--- Unlimited Web Browser History ---\n";

    while (true) {
        cout << "\n1. Visit new URL\n2. Press Back button\n3. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter URL (e.g., google.com): ";
                cin >> url;
                browser.visit(url);
                browser.displayCurrent();
                break;
            case 2:
                browser.back();
                browser.displayCurrent();
                break;
            case 3:
                cout << "Closing browser...\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}