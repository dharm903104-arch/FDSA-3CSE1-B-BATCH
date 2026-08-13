#include <iostream>
using namespace std;

int main()
{
    int n,h;

    cout<<"Enter Number Of item: ";
    cin>>n;
    cout<<"Enter Number Of Hour: ";
    cin>>h;

    int a[n];
    for(int i = 0; i < n; i++)
    {
        cout<<"Enter Items: ";
        cin>>a[i];
    }

    int shift = h % n;

    cout<<"Final Display: ";
    for(int i = 0; i < n; i++)
    {
        cout<<a[(i + shift) % n]<<" ";
    }
    
    return 0;
}