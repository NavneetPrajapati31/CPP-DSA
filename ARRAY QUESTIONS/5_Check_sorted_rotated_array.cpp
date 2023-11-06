#include<iostream>
#include<vector>

using namespace std;


bool check(vector<int>& nums) {
        int cnt = 0;
        for(int i=1;i<nums.size();i++) 
        {
            if(nums[i] < nums[i-1])
                cnt++;
        }
        if(nums[nums.size()-1] > nums[0])
            cnt++;
        
        return cnt<=1;
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

    if(check(arr))
    {
        cout<<"yes"<<endl;
    }

    else
    {
        cout<<"no";
    }

return 0;


}