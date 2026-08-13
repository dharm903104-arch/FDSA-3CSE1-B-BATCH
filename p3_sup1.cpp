#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& rolls) {
    const int MAX = 100;
    vector<int> count(MAX + 1, 0);

    for (int num : rolls) {
        count[num]++;
    }

    rolls.clear();
    for (int i = 1; i <= MAX; i++) {
        while (count[i] > 0) {
            rolls.push_back(i);
            count[i]--;
        }
    }
}

int main() {
    vector<int> rolls = {5, 3, 2, 5, 1, 4, 3};
    countingSort(rolls);

    cout << "Sorted roll numbers: ";
    for (int num : rolls) cout << num << " ";
    return 0;
}
