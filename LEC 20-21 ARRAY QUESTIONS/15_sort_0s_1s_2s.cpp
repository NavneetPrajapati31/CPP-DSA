//Approach 1 - any sorting algo
//Approach 2 - count0, count1, count2 and update array
//Approach 3 - Optimal solution - DNF algo

#include<iostream>
#include<vector>
using namespace std;

void sortArray(vector<int>& arr, int n)
{
    // Write your code here
int count0=0;
int count1 =0;
int count2 =0;

for(int i=0;i<n;i++)
{
    if(arr[i] ==0)
    {
        count0++;
    }

    else if(arr[i] ==1)
    {
        count1++;
    }

    else if(arr[i] ==2)
    {
        count2++;
    }
}

cout<<count0<<endl;
cout<<count1<<endl;
cout<<count2<<endl;

int ans[n] ={0};
int i=0;
    while(count0>0)
    {
        ans[i] = 0;
        i++;
        count0--;
    }

    while(count1>0)
    {
        ans[i] = 1;
        i++;
        count1--;
    }

    while(count2>0)
    {
        ans[i] = 2;
        i++;
        count2--;
    }

    for(int i=0;i<n;i++)
    {
         cout<<ans[i]<<" ";
     }

}

int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(0);
    arr.push_back(2);
    arr.push_back(1);

    sortArray(arr,6);

}