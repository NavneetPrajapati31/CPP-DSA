#include<iostream>
using namespace std;


void saydigits(int n, string arr[])
{
    //base case
    if(n==0)
    {
        return ;
    }

    //processing
    int digit=n%10;
    n=n/10;


    //recursive relation
    saydigits(n,arr);
    cout<<arr[digit]<<" ";

}


int main()
{
    int n;
    cin>>n;

    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

    saydigits(n,arr);

    return 0;

}