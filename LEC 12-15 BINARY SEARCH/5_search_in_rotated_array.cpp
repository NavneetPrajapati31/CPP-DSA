//SEARCH IN ROTATED AND SORTED ARRAY!!


#include<iostream>
using namespace std;


bool binsearch(int arr[],int s,int e,int key)
{
int start=s;
int end=e;
int mid=s+(e-s)/2;

while(start <= end)
{
    if(arr[mid]==key)
    {
        return 1;
    }

    if(key<arr[mid])
    {
        e=mid-1;
    }

    else if(key>arr[mid])
    {
        s=mid+1;
    }

mid=start+(end-start)/2;

}

return 0;

}


int getpivot(int arr[],int n )
{
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;

while(s < e)
{

if(arr[mid]>=arr[0])
{
    s=mid+1;
}

else
{
    e=mid;
}

mid=s+(e-s)/2;

}
return s;
}




bool searchrotated(int arr[],int n,int key)
{
int pivot = getpivot(arr,n);

if(key>=arr[pivot] && key <= arr[n-1])
{
    return binsearch(arr,pivot,n-1,key);
}

else
{
    return binsearch(arr,0,pivot-1,key);
}

}


int main()
{
int arr[5]={19,20,4,6,8};

if(searchrotated(arr,5,6))
{
    cout<<"yes"<<endl;
}
else
{
    cout<<"no"<<endl;
}

}