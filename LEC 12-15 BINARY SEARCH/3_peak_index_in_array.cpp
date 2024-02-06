//FINDING THE INDEX OF PEAK ELEMENT IN AN ARRAY!!


#include<iostream>
using namespace std;

int peakindex(int arr[],int n)
{
int s=0;
int e=n-1;
int mid=s+(e-s)/2;

while(s < e)
{

if(arr[mid]>arr[mid+1])
{
e=mid;
}

else
{
    s=mid+1;
}

mid=s+(e-s)/2;

}
return s;
}

int main()
{

int n;
cin>>n;

int arr[n];

for(int i=0;i<n;i++)
{
    cin>>arr[i];
    
}

cout<<peakindex(arr,n);

}