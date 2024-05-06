#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int> arr, int n)
{
    vector<vector<int>> subarrays;
     for(int i=0;i<n;i++)
    {
        vector<int> temp;
        temp.push_back(arr[i]);
        subarrays.push_back(temp);

        for(int j=i+1;j<n;j++)
        {
             temp.push_back(arr[j]);
             subarrays.push_back(temp);
        }
    }

    subarrays.push_back({});

for (int i = 0; i < subarrays.size(); i++) {
        cout << "[";
        for (int j = 0; j < subarrays[i].size(); j++) {
            cout << subarrays[i][j];
            if (j < subarrays[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < subarrays.size() - 1) {
            cout << ", ";
        }
}

vector<int> sums;
int sum=0;
for (int i = 0; i < subarrays.size(); i++) {
    sum=0;
        for (int j = 0; j < subarrays[i].size(); j++) {
            sum+=subarrays[i][j];
        }
        sums.push_back(sum);
}

cout<<endl;

for(int i=0;i<sums.size();i++)
{
    cout<<sums[i]<<" ";
}

int ans;


}


int main()
{
    vector<int> arr;
    arr.push_back(-7);
    arr.push_back(-8);
    arr.push_back(-16);
    arr.push_back(-4);
    arr.push_back(-8);
    arr.push_back(-5);
        arr.push_back(-7);
        arr.push_back(-11);
        arr.push_back(-10);
                arr.push_back(-12);
                        arr.push_back(-4);
                                arr.push_back(-6);
                                        arr.push_back(-4);
                                                arr.push_back(-16);
                                                        arr.push_back(-10);

cout<<maxSubarraySum(arr, 15);
    
    }
