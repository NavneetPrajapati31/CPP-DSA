//https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbVF3dTUtRVoxNjZkU0xPbm15enBwTXZMUkYwUXxBQ3Jtc0tsQ2tzVXRmWnhGUFM3RkVILUVTRmdsRG8tNGVkSURORy1TYXl2eEY5SkRPTTY2MjA0VkpaUGhULXNVTUpyMmVLTVpRZENUX0U0YVBnNXJkV3BrSENHdGhYQW5Jd3dZZ2lLczA4Q2hXRzItTmVFU29UYw&q=https%3A%2F%2Fbit.ly%2F3EstWN7&v=7kIVfVY6Axk



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


void insertionSort(vector<int> &arr, int n){
    
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

    insertionSort(arr,n);
    printarr(arr,n);


}