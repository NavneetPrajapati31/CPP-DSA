//https://www.naukri.com/code360/problems/connect-n-ropes-with-minimum-cost_630476?leftPanelTabValue=PROBLEM

#include<bits/stdc++.h>

long long connectRopes(int* arr, int n)
{
    priority_queue<long long ,  vector<long long> , greater<long long> > pq;

    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
    }

    long long ans=0;

    while(pq.size()>1)
    {
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        ans+=(a+b);
        pq.push(a+b);
    }

    return ans;
}
