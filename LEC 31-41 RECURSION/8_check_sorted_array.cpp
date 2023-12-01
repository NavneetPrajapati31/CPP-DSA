#include<iostream>
using namespace std;

bool checksorted(int arr[],int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }

    if(arr[0]>arr[1])
    {
    return 0;
    }

    else
    {
        bool ans = checksorted(arr+1,n-1);
        return ans;
    }

}

 int main()
 {
    int arr[5]={4,5,70,8,9};
    cout<<checksorted(arr,5);

 }