#include <iostream>

using namespace std;

struct ScoreNode {
    int score;
    ScoreNode* left;
    ScoreNode* right;

    ScoreNode(int s) {
        score = s;
        left = nullptr;
        right = nullptr;
    }
};

ScoreNode* insertScore(ScoreNode* root, int score) {
    if (root == nullptr) {
        return new ScoreNode(score);
    }
    if (score < root->score) {
        root->left = insertScore(root->left, score);
    } else {
        root->right = insertScore(root->right, score);
    }
    return root;
}

void findKthSmallest(ScoreNode* root, int k, int& counter, int& result, bool& found) {
    if (root == nullptr || found) return;

    findKthSmallest(root->left, k, counter, result, found);

    if (!found) {
        counter++;
        if (counter == k) {
            result = root->score;
            found = true;
            return;
        }
    }

    findKthSmallest(root->right, k, counter, result, found);
}

void printInOrder(ScoreNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->score << " ";
    printInOrder(root->right);
}

void deleteTree(ScoreNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    ScoreNode* leaderboard = nullptr;
    int n, score, k;

    cout << "--- Competition Leaderboard: k-th Smallest Score Finder ---\n";
    cout << "Enter the number of participant scores: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid count. Exiting.\n";
        return 0;
    }

    cout << "Enter " << n << " scores (separated by spaces): ";
    for (int i = 0; i < n; i++) {
        cin >> score;
        leaderboard = insertScore(leaderboard, score);
    }

    cout << "All recorded scores in ascending rank order: ";
    printInOrder(leaderboard);
    cout << "\n";

    cout << "Enter rank k to find (1 = lowest score): ";
    if (cin >> k) {
        if (k <= 0) {
            cout << "Error: k must be a positive integer greater than 0.\n";
        } else {
            int counter = 0;
            int result = -1;
            bool found = false;

            findKthSmallest(leaderboard, k, counter, result, found);

            if (found) {
                cout << "The " << k << "-th smallest score on the leaderboard is: " << result << "\n";
            } else {
                cout << "Error: k (" << k << ") is greater than the total number of scores (" << counter << ") in the tree!\n";
            }
        }
    }

    deleteTree(leaderboard);
    return 0;
}
