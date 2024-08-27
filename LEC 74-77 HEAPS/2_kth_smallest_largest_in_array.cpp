//Code 360 : https://www.naukri.com/code360/problems/kth-smallest-largest-element-in-an-array_1230551
//Leetcode : https://leetcode.com/problems/kth-largest-element-in-an-array/description/

#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) 
{
        priority_queue<int, vector<int> , greater<int>> pq;

        for(int i=0;i<k;i++)
        {
            pq.push(nums[i]);
        }

        for(int i=k;i<nums.size();i++)
        {
            if(nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
}

int findKthSmallest(vector<int>& nums, int k) 
{
        priority_queue<int> pq;

        for(int i=0;i<k;i++)
        {
            pq.push(nums[i]);
        }

        for(int i=k;i<nums.size();i++)
        {
            if(nums[i] < pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
}