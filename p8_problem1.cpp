#include <iostream>
#include <string>

using namespace std;

struct EmployeeNode {
    string name;
    string role;
    EmployeeNode* left;
    EmployeeNode* right;

    EmployeeNode(string n, string r) {
        name = n;
        role = r;
        left = nullptr;
        right = nullptr;
    }
};

struct QueueNode {
    EmployeeNode* treeNode;
    QueueNode* next;

    QueueNode(EmployeeNode* node) {
        treeNode = node;
        next = nullptr;
    }
};

class SimpleQueue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    SimpleQueue() {
        front = rear = nullptr;
    }

    ~SimpleQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(EmployeeNode* node) {
        QueueNode* qn = new QueueNode(node);
        if (isEmpty()) {
            front = rear = qn;
        } else {
            rear->next = qn;
            rear = qn;
        }
    }

    EmployeeNode* dequeue() {
        if (isEmpty()) return nullptr;
        QueueNode* temp = front;
        EmployeeNode* node = temp->treeNode;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        return node;
    }
};

void printInOrder(EmployeeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->name << " (" << root->role << ") | ";
    printInOrder(root->right);
}

void printPreOrder(EmployeeNode* root) {
    if (root == nullptr) return;
    cout << root->name << " (" << root->role << ") | ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(EmployeeNode* root) {
    if (root == nullptr) return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->name << " (" << root->role << ") | ";
}

void printLevelOrder(EmployeeNode* root) {
    if (root == nullptr) return;

    SimpleQueue q;
    q.enqueue(root);

    while (!q.isEmpty()) {
        EmployeeNode* current = q.dequeue();
        cout << current->name << " (" << current->role << ") | ";

        if (current->left != nullptr) {
            q.enqueue(current->left);
        }
        if (current->right != nullptr) {
            q.enqueue(current->right);
        }
    }
}

void deleteTree(EmployeeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    cout << "--- Company Organizational Hierarchy Tree ---\n";

    EmployeeNode* ceo = new EmployeeNode("Alice", "CEO");
    ceo->left = new EmployeeNode("Bob", "VP-Tech");
    ceo->right = new EmployeeNode("Carol", "VP-Ops");

    ceo->left->left = new EmployeeNode("David", "Dev-Lead");
    ceo->left->right = new EmployeeNode("Emma", "QA-Lead");
    ceo->right->right = new EmployeeNode("Frank", "Operations-Lead");

    cout << "\nTree structure built successfully.\n";

    cout << "\n1. HR Department (In-order: Left -> Root -> Right):\n";
    printInOrder(ceo);
    cout << "\n";

    cout << "\n2. Archive Department (Pre-order: Root -> Left -> Right):\n";
    printPreOrder(ceo);
    cout << "\n";

    cout << "\n3. Payroll Department (Post-order: Left -> Right -> Root):\n";
    printPostOrder(ceo);
    cout << "\n";

    cout << "\n4. Floor Manager (Level-order / BFS: Top to Bottom):\n";
    printLevelOrder(ceo);
    cout << "\n";

    deleteTree(ceo);
    return 0;
}
