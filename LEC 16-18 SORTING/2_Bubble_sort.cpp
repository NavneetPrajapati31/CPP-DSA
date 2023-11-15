#include<iostream>
#include<vector>
using namespace std;

void printarr(vector<int> arr,int n)
{
    for(int i:arr)
    {
        cout<<i<<" ";
    }
}

void bubbleSort(vector<int>& arr, int n)
{   
    for(int i = 1; i<n; i++) {
        //for round 1 to n-1
        bool swapped = false;
        
        for(int j =0; j<n-i; j++) {
            
            //process element till n-i th index
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            
        }
        
        if(swapped == false) {
            //already sorted
            break;
        }
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

    bubbleSort(arr,n);
    printarr(arr,n);

   return 0;
}