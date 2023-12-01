#include<iostream>
using namespace std;

bool linsearch(int arr[],int n,int key)
{
    if(n==0)
    {
        return 0;
    }

    if(arr[0]==key)
    {
        return 1;
    }
    else
    {
        return linsearch(arr+1,n-1,key);
    }

}

 int main()
 {
    int arr[5]={4,5,7,8,9};
    cout<<linsearch(arr,5,98);

 }