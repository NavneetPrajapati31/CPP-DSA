#include<iostream>
#include<vector>
using namespace std;


void printarr(vector<int> arr,int n)
{
    for(int i:arr)
    {
        cout<<i<<" ";
    }
}


void movezeroes(vector<int> nums)
{
    //shift all non zero elements to the left

    int nonzero=0;

    for(int j=0;j<nums.size();j++)
    {
        if(nums[j]!=0)
        {
            swap(nums[j],nums[nonzero]);
            nonzero++;
        }

    }
}                                                                                       


int main()
{
     int n,element;
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        cin>>element;
        arr.push_back(element);
    }

    movezeroes(arr);
    printarr(arr,n);

}