#include<iostream>
using namespace std;

int arraysum(int arr[],int n)
{

    if(n==0)
    {
        return 0;
    }

    if(n==1)
    {
         return arr[0];
    }

int value=arraysum(arr+1,n-1);
int sum = arr[0]+value;
return sum;

}

 int main()
 {
    int arr[5]={4,5,7,8,9};
    cout<<arraysum(arr,5);

 }