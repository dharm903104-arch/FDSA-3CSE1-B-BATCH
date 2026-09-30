#include <iostream>

using namespace std;

struct BookNode {
    int code;
    BookNode* left;
    BookNode* right;

    BookNode(int c) {
        code = c;
        left = nullptr;
        right = nullptr;
    }
};

BookNode* insertBook(BookNode* root, int code) {
    if (root == nullptr) {
        return new BookNode(code);
    }

    if (code < root->code) {
        root->left = insertBook(root->left, code);
    } else if (code > root->code) {
        root->right = insertBook(root->right, code);
    } else {
        cout << "Book code " << code << " already exists in library catalog (duplicate skipped).\n";
    }

    return root;
}

void printInOrder(BookNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->code << " ";
    printInOrder(root->right);
}

void deleteTree(BookNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    BookNode* libraryCatalog = nullptr;
    int n, code;

    cout << "--- School Library Book Catalog (Binary Search Tree) ---\n";
    cout << "Enter the number of books arriving: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid count. Exiting.\n";
        return 0;
    }

    cout << "Enter " << n << " book codes (separated by spaces): ";
    for (int i = 0; i < n; i++) {
        cin >> code;
        libraryCatalog = insertBook(libraryCatalog, code);
    }

    cout << "\nIn-order Sequence of Book Codes (Shelved Arrangement):\n";
    printInOrder(libraryCatalog);
    cout << "\n";

    deleteTree(libraryCatalog);
    return 0;
}
