#include <iostream>
#include <vector>

using namespace std;

const int NUM_SHELVES = 10;

struct BookNode {
    int bookCode;
    BookNode* next;

    BookNode(int code) {
        bookCode = code;
        next = nullptr;
    }
};

class LibraryShelfSystem {
private:
    BookNode* shelves[NUM_SHELVES];

public:
    LibraryShelfSystem() {
        for (int i = 0; i < NUM_SHELVES; i++) {
            shelves[i] = nullptr;
        }
    }

    ~LibraryShelfSystem() {
        for (int i = 0; i < NUM_SHELVES; i++) {
            BookNode* curr = shelves[i];
            while (curr != nullptr) {
                BookNode* temp = curr;
                curr = curr->next;
                delete temp;
            }
            shelves[i] = nullptr;
        }
    }

    void placeBook(int code) {
        int shelfIndex = code % NUM_SHELVES;
        BookNode* newBook = new BookNode(code);

        newBook->next = shelves[shelfIndex];
        shelves[shelfIndex] = newBook;

        cout << "Book " << code << " placed on Shelf " << shelfIndex << ".\n";
    }

    void displayShelves() {
        cout << "\n--- Final Contents of All 10 Shelves (Separate Chaining) ---\n";
        for (int i = 0; i < NUM_SHELVES; i++) {
            cout << "Shelf " << i << ": ";
            BookNode* curr = shelves[i];
            if (curr == nullptr) {
                cout << "[ EMPTY ]\n";
            } else {
                while (curr != nullptr) {
                    cout << "[" << curr->bookCode << "] -> ";
                    curr = curr->next;
                }
                cout << "NULL\n";
            }
        }
        cout << "----------------------------------------------------------\n";
    }
};

int main() {
    LibraryShelfSystem library;
    int choice;

    cout << "--- Library Book Shelving System (Separate Chaining) ---\n";
    cout << "1. Run with sample books (multiple books on same shelf)\n";
    cout << "2. Enter custom book codes\n";
    cout << "Choice: ";

    if (!(cin >> choice)) return 0;

    if (choice == 1) {

        vector<int> sampleBooks = {13, 25, 47, 23, 87, 103, 50, 92, 33};
        cout << "\nPlacing sample books: 13, 25, 47, 23, 87, 103, 50, 92, 33\n\n";
        for (int b : sampleBooks) {
            library.placeBook(b);
        }
        library.displayShelves();
    } else {
        int n, code;
        cout << "Enter number of books: ";
        cin >> n;
        cout << "Enter " << n << " book codes (separated by space): ";
        for (int i = 0; i < n; i++) {
            cin >> code;
            library.placeBook(code);
        }
        library.displayShelves();
    }

    return 0;
}
