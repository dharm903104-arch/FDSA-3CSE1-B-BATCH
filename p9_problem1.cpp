#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int current, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[current] = true;
    cout << "Building " << current << " -> ";

    for (int neighbor : adj[current]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

void bfs(int start, const vector<vector<int>>& adj, int numBuildings) {
    vector<bool> visited(numBuildings, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << "Building " << current << " -> ";

        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void runInspection(int numBuildings, const vector<vector<int>>& adj, int start) {
    cout << "\nStarting Inspection from Building " << start << ":\n";

    cout << "\n[Team 1 - Deep Inspection (DFS / LIFO Call Stack)]:\n";
    vector<bool> visitedDFS(numBuildings, false);
    dfs(start, adj, visitedDFS);
    cout << "DONE\n";

    cout << "\n[Team 2 - Level-by-Level Inspection (BFS / FIFO Queue)]:\n";
    bfs(start, adj, numBuildings);
    cout << "DONE\n";
}

int main() {
    cout << "--- City Disaster Relief Inspection Network ---\n";
    cout << "1. Use default city network (6 buildings: 0 to 5)\n";
    cout << "2. Enter custom city network\n";
    cout << "Choice: ";

    int choice;
    if (!(cin >> choice)) return 0;

    if (choice == 1) {

        int numBuildings = 6;
        vector<vector<int>> adj(numBuildings);

        auto addRoad = [&](int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        };

        addRoad(0, 1);
        addRoad(0, 2);
        addRoad(1, 3);
        addRoad(1, 4);
        addRoad(2, 4);
        addRoad(3, 5);
        addRoad(4, 5);

        cout << "\nSample city network loaded: 6 buildings, 7 roads.\n";
        cout << "Road connections: 0-1, 0-2, 1-3, 1-4, 2-4, 3-5, 4-5\n";

        runInspection(numBuildings, adj, 0);
    } else {
        int numBuildings, numRoads;
        cout << "Enter number of buildings: ";
        cin >> numBuildings;
        cout << "Enter number of roads: ";
        cin >> numRoads;

        vector<vector<int>> adj(numBuildings);
        cout << "Enter " << numRoads << " roads as pairs (u v, 0-indexed):\n";
        for (int i = 0; i < numRoads; i++) {
            int u, v;
            cin >> u >> v;
            if (u >= 0 && u < numBuildings && v >= 0 && v < numBuildings) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        int start;
        cout << "Enter starting building (0 to " << numBuildings - 1 << "): ";
        cin >> start;

        if (start >= 0 && start < numBuildings) {
            runInspection(numBuildings, adj, start);
        } else {
            cout << "Invalid starting building.\n";
        }
    }

    return 0;
}
