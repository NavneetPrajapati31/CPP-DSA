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


void insertionSort(int n, vector<int> &arr){
    
    for(int i = 1; i<n; i++) {
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--) {
            
            if(arr[j] > temp) {
                //shift
                arr[j+1] = arr[j];
            }
            else { // rukk jao
                break;
            }
            
        }
        //copy temp value
        arr[j+1] = temp;  
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

    insertionSort(n,arr);
    printarr(arr,n);


}