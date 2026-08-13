#include <iostream>
#include <vector>
using namespace std;

int booksit(vector<int> b, int target)
{
    int left = 0; 
    int right = b.size() - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(b[mid] == target)
        return mid + 1;
        else if(b[mid] < target)
        left = mid + 1;
        else
        right = mid - 1;
    }
    return -1;
}

int bookre(vector<int> b, int target,int left, int right)
{
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(b[mid] == target)
        return mid + 1;
        else if(b[mid] < target)
        return bookre(b,target,mid+1,right) + 1;
        else
        return bookre(b,target,left,mid-1) + 1;
    }
    return -1;
}

int main()
{
    vector<int> bookCode = {10,11,12,13,14,15,16,17,18,19,20};
    int target = 15;
    cout<<"by iterative: "<<booksit(bookCode,target)<<endl;
    cout<<"by recursive: "<<bookre(bookCode,target,0,bookCode.size());
    return 0;
}