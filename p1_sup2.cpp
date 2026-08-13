#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of voters: ";
    cin >> n;
    vector<int> log(n);

    cout << "Enter voter IDs: ";
    for (int i = 0; i < n; i++) cin >> log[i];

    unordered_map<int, int> count;
    for (int id : log) count[id]++;

    cout << "Voters who voted exactly once: ";
    for (auto entry : count) {
        if (entry.second == 1) cout << entry.first << " ";
    }
    return 0;
}