#include <iostream>
#include <vector>
using namespace std;

void SortColor(vector<int>& arr) {
    int low = 0, mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low++], arr[mid++]);
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { 
            swap(arr[mid], arr[high--]);
        }           
    }
}

int main() {
    vector<int> color = {0,0,1,0,2,1,2,1,2,0,1,2};
    SortColor(color);
    for (int r : color) cout << r << " ";
    return 0;
}
