//TO FIND THE FIRST AND LAST OCCURENCE OF ANY KEY USING BINARY SEARCH!!
//TOTAL NO OF OCCURENCES

#include<iostream>
using namespace std;

int firstocc(int arr[],int n,int key)
{
int s=0;
int e=n-1;
int mid=s+(e-s)/2;
int ans=-1;

while(s <= e)
{
    if(arr[mid]==key)
    {
        ans=mid;
        e=mid-1;
    }

    else if(key<arr[mid])
    {
        e=mid-1;
    }

    else if(key>arr[mid])
    {
        s=mid+1;
    }

mid=s+(e-s)/2;

}
return ans;
}

int lastocc(int arr[],int n,int key)
{
int s=0;
int e=n-1;
int mid=s+(e-s)/2;
int ans=-1;

while(s <= e)
{
    if(arr[mid]==key)
    {
        ans=mid;
        s=mid+1;
    }

    else if(key<arr[mid])
    {
        e=mid-1;
    }

    else if(key>arr[mid])
    {
        s=mid+1;
    }

mid=s+(e-s)/2;

}
return ans;
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

int key;
cin>>key;

cout<<firstocc(arr,n,key)<<endl;
cout<<lastocc(arr,n,key)<<endl;
//total occurences

cout<<(lastocc(arr,n,key)-firstocc(arr,n,key)+1);

}