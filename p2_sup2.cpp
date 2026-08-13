#include <iostream>
#include <vector>
using namespace std;

bool searchGrid(vector<vector<int>>& grid, int target) {
    int rows = grid.size(), cols = grid[0].size();
    int r = 0, c = cols - 1; 
    while (r < rows && c >= 0) {
        if (grid[r][c] == target) return true;
        else if (grid[r][c] > target) c--;   
        else r++;   
    }
    return false;
}

int main() {
    vector<vector<int>> grid = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    int target = 5;
    cout << (searchGrid(grid, target) ? "Found" : "Not Found") << endl;
}
