#include<iostream>
using namespace std;

int partition(int *arr, int s, int e)
{

int pivot=arr[s];
int cnt=0;
for(int i=s+1;i<=e;i++)
{
    if(arr[i]<pivot)
    {
        cnt++;
    }
}

//place pivot at right index
int pivotindex=s+cnt;
swap(arr[pivotindex],arr[s]);

//left and right

int i=s,j=e;

while(i<pivotindex && j> pivotindex)
{
    while(arr[i]<pivot)
    {
        i++;
    }

     while(arr[j]>pivot)
    {
        j--;
    }

    if(i<pivotindex && j> pivotindex)
    {
        swap(arr[i],arr[j]);
    }

}

return pivotindex;

}

void quicksort(int *arr,int s, int e)
{

if(s>=e)
{
    return;
}

//partition
int p=partition(arr,s,e);

//left side
quicksort(arr,s,p-1);

//right side
quicksort(arr,p+1,e);


}


int main()
{
int arr[5]={3,4,2,6,8};

quicksort(arr,0,4);

for(int i=0;i<5;i++)
{
    cout<<arr[i]<<" ";
}

}