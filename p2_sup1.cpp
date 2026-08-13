#include <iostream>
#include <vector>
using namespace std;

int missingrolln(vector<int> roll, int k)
{
    int prev = 0;
    for(int r : roll)
    {
        int gap = r - prev - 1;
        if(k <= gap)
        return prev + k;
        k -= gap;
        prev = r;
    }
    return prev + k;
}

int main()
{
    vector<int> roll = {1,2,4,5,8,9};
    int k = 3;
    cout<<"Missing Roll is: "<<missingrolln(roll,k);
}