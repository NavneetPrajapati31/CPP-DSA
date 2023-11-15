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


void rotate(vector<int> nums, int k) {
      
    // just to practice the modulus approach
      int n = nums.size();
      vector<int> temp(n);
      
      
      for(int i =0;i<n;i++) {
        
        temp[(i+k)%n] = nums[i];
        
      }
      
      
      for(int i=0;i<nums.size();i++) 
      {
        nums[i] = temp[i];
      }
      
    }


int main()
{
     int n,element,k;
    cin>>n>>k;
    

    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        cin>>element;
        arr.push_back(element);
    }

    rotate(arr,k);
    printarr(arr,n);

}