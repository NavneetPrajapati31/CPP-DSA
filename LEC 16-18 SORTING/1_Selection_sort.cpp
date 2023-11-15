#include<iostream>
#include<vector>
using namespace std;

void printvector(vector<int> v)
{
    for(int i:v)
    {
        cout<< i <<" ";
    }
}

void selectionSort(vector<int>& arr, int n)
{   
    for(int i = 0; i < n-1; i++ ) {
        int minIndex = i;
        
        for(int j = i+1; j<n; j++) {
            
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
            
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main()
{
    int n,element;
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        cin>>element;
        arr.push_back(element);
    }

    selectionSort(arr,n);
    printvector(arr);

   return 0;
}