#include <iostream>
#include <vector>
using namespace std;

int plateit(vector<string> plate, string target)
{
    for(int i = 0; i < plate.size(); i++)
    {
        if(plate[i] == target)
        {
            return i+1;
            break;
        }
    }
    return -1;
}

int platere(vector<string> plates, string tar,int st = 0)
{
   if(st >= plates.size())
   return -1;
   if(plates[st] == tar)
   return st+1;
   return platere(plates,tar,st+1);
}

int main()
{
    vector<string> p = {"AX01BC0121", "VC02CD0123", "AX01BC2548", "BH01GH0185", "RH02BC6542"};
    string targett = "AX01BC2548";
    cout<<"By iterative: "<<plateit(p,targett)<<endl;
    cout<<"By recursive: "<<platere(p,targett);
    return 0;
}