//BINARY SEARCH BASIC CODE                                              

/*
FINDING THE MID ELEMENT OF ARRAY,
THEN AS PER GIVEN 3 CONDITIONS (==,>,<) TRAVERSE!!
RETURN KEY FOUND OR NOT
*/
 

#include<iostream>
using namespace std;

bool binsearch(int arr[],int n,int key)
{
int s=0;
int e=n-1;
int mid=s+(e-s)/2;

while(s <= e)
{
    if(arr[mid]==key)
    {
        return 1;
    }

    if(arr[mid]>key)
    {
        e=mid-1;
    }

    else
    {
        s=mid+1;
    }

mid=s+(e-s)/2;

}

return 0;

}


int main()
{

//arraysize

int n;
cin>>n;

//array

int arr[n];

for(int i=0;i<n;i++)
{
    cin>>arr[i];
    
}

//key

int key;
cin>>key;


if(binsearch(arr,n,key))
{
    cout<<"present"<<endl;
}

else
{
    cout<<"not present";
}

return 0;

}