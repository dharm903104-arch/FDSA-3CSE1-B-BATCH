#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {

    int n;
    cout<<"Enter Number Of Book Borrowed: ";
    cin>>n;
    vector<int> logs(n);
    for(int i = 0; i < n; i++)
    {   
        cout<<"Enter Book Id: ";
        cin>>logs[i];
    }
    
    unordered_map<int,int> count(n);
    for(int id : logs)
    {
        count[id]++;
    }
    cout<<"Book Borrowed More Than One Time: ";
    for(auto ent : count)
    {
        if(ent.second > 1)
        {
            cout<<ent.first<<" ";
        }
    }
    return 0;
}
