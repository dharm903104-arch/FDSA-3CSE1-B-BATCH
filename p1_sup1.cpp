#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cout << "Enter total classrooms (n): ";
    cin >> n;
    cout << "Enter reported count (m): ";
    cin >> m;

    unordered_set<int> reported;
    cout << "Enter reported room numbers: ";
    for (int i = 0; i < m; i++) {
        int room;
        cin >> room;
        reported.insert(room);
    }

    cout << "Missing rooms: ";
    for (int i = 1; i <= n; i++) {
        if (reported.find(i) == reported.end()) cout << i << " ";
    }
    return 0;
}