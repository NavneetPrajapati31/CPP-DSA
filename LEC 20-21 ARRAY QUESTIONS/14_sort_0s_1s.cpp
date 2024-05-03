#include<iostream>
#include<vector>
using namespace std;

//Brute force approach

void sort01(vector<int> &arr)
{
    int i=0;
    int j=arr.size()-1;
    while(i<j)
    {
        while(arr[i] == 0)
        {
            i++;
        }

        while(arr[j] == 1)
        {
            j--;
        }

        if(i<j)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);

    sort01(v);

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }


}