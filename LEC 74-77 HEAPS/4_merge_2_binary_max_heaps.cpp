//https://www.naukri.com/code360/problems/merge-two-binary-max-heaps_1170049

#include <bits/stdc++.h> 

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest] , arr[i]);
        heapify(arr,n,largest);
    }
}

vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        v.push_back(arr1[i]);
    }

    for(int i=0;i<m;i++)
    {
        v.push_back(arr2[i]);
    }

    int size = v.size();

    for (int i = size/2 - 1; i >= 0; i--) {
        heapify(v, size, i);
    }

    return v;
}