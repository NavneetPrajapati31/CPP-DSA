#include<iostream>
using namespace std;

bool binsearch(int arr[],int s,int e,int key)
{
    if(s>e)
    {
        return 0;
    }

    int mid=s+(e-s)/2;

    if(arr[mid]==key)
    {
        return 1;
    }

    if(arr[mid]<key)
    {
        return binsearch(arr,mid+1,e,key);
    }

    else
    {
        return binsearch(arr,s,mid-1,key);
    }

}

 int main()
 {
    int arr[5]={4,5,7,8,9};
    cout<<binsearch(arr,0,4,9);

 }