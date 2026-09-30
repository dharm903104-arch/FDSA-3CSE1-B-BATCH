#include <iostream>
#include <vector>

using namespace std;

bool hasCycleDFS(int current, int parent, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[current] = true;

    for (int neighbor : adj[current]) {

        if (!visited[neighbor]) {
            if (hasCycleDFS(neighbor, current, adj, visited)) {
                return true;
            }
        }

        else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

bool detectLoop(int numTasks, const vector<vector<int>>& adj) {
    vector<bool> visited(numTasks, false);

    for (int i = 0; i < numTasks; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(i, -1, adj, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cout << "--- Project Task Dependency Loop Detector (Undirected Graph) ---\n";
    cout << "1. Run sample with loop (Tasks 0-1, 1-2, 2-0)\n";
    cout << "2. Run sample without loop (Tasks 0-1, 1-2, 2-3)\n";
    cout << "3. Enter custom task dependencies\n";
    cout << "Choice: ";

    int choice;
    if (!(cin >> choice)) return 0;

    int numTasks = 0;
    vector<vector<int>> adj;

    if (choice == 1) {
        numTasks = 4;
        adj.resize(numTasks);

        adj[0].push_back(1); adj[1].push_back(0);
        adj[1].push_back(2); adj[2].push_back(1);
        adj[2].push_back(0); adj[0].push_back(2);
        adj[2].push_back(3); adj[3].push_back(2);
        cout << "\nSample 1 Loaded: 4 tasks with dependencies 0-1, 1-2, 2-0, 2-3\n";
    } else if (choice == 2) {
        numTasks = 4;
        adj.resize(numTasks);

        adj[0].push_back(1); adj[1].push_back(0);
        adj[1].push_back(2); adj[2].push_back(1);
        adj[2].push_back(3); adj[3].push_back(2);
        cout << "\nSample 2 Loaded: 4 tasks with dependencies 0-1, 1-2, 2-3\n";
    } else {
        int numEdges;
        cout << "Enter number of tasks: ";
        cin >> numTasks;
        cout << "Enter number of dependency connections: ";
        cin >> numEdges;

        adj.resize(numTasks);
        cout << "Enter " << numEdges << " connections as pairs (u v, 0-indexed):\n";
        for (int i = 0; i < numEdges; i++) {
            int u, v;
            cin >> u >> v;
            if (u >= 0 && u < numTasks && v >= 0 && v < numTasks) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }

    bool loopExists = detectLoop(numTasks, adj);

    cout << "\nResult: ";
    if (loopExists) {
        cout << "Yes\n(A circular dependency loop exists!)\n";
    } else {
        cout << "No\n(No loops detected. Dependencies are valid!)\n";
    }

    return 0;
}
