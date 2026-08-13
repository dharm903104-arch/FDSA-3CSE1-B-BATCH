#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int> arr)
{
    int n = arr.size();
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }

    for(int r : arr) cout<<r<<" ";
    cout<<endl;
}

void SelectionSort(vector<int> arr)
{
    int n = arr.size();
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        for(int j = i+1; j < n;j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }

    for(int r : arr) cout<<r<<" ";
    cout<<endl;
}

void InsertionSort(vector<int> arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];  
        int j = i - 1;

   
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; 
    }
    for(int r : arr) cout<<r<<" ";
}
    


int main()
{
    vector<int> roll = {10,50,60,70,20,30,90,100,40,80};

    BubbleSort(roll);
    SelectionSort(roll);
    InsertionSort(roll);

    return 0;
}