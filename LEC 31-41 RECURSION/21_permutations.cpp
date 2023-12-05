//https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbC0zSnltdWpMb2NSdzI3R0RTZDZQQXB2VmEwd3xBQ3Jtc0ttSlBudGVMSzVodjBPQmFNTHhaeVBlQ1ktaW5ZbVZ2X3pJSUtnVE5aMVhTVnZGV3BRVmhWOTdQMWpvbnRRel9OUEhHdm91NEJ1d2pyaUhOQ2tMc2xoZnNqaEVXZ0ZoOGU0NV9oRUhKSU45c1VRTlJPRQ&q=https%3A%2F%2Fleetcode.com%2Fproblems%2Fpermutations%2F&v=va3NEycUxsg


#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums, int index, vector<vector<int>> &ans)
{
    if(index>=nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int j=index;j<nums.size();j++)
    {
        swap(nums[index],nums[j]);
        solve(nums,index+1,ans);
        swap(nums[index],nums[j]);

    }

}

vector<vector<int>> permut(vector<int> nums )
{
int index=0;
vector<vector<int>> ans;
solve(nums,index,ans);
return ans;

}

int main()
{


}