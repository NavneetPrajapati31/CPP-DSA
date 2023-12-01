//https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbW9XLTVGZXl3N1NyMWU3cHQ5SmNSUS1uUlVBZ3xBQ3Jtc0tuRjRCa3IxanlnSlRObzBJdWV4b19fWDBDcGUtcnZKXzQ2bGl4OC1zZlNUTVNIekROZDdBbTNSLTVheGQ2cjZRa3RNbF9uN240Nm1ERU95QWhiSmZ4VWUzM3l2bmtENzJlYmV3LVpEbDhJdVNaWVBLRQ&q=https%3A%2F%2Fleetcode.com%2Fproblems%2Fsubsets%2F&v=V0IgCltYgg4


#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    if(index>=nums.size())
    {
        ans.push_back(output);
        return;
    }

    //exclude
    solve(nums,output,index+1,ans);

    //include
    int element=nums[index];
    output.push_back(element);
    solve(nums,output,index+1,ans);

}

vector<vector<int>> subsets(vector<int>& nums)
    {
         
        vector<vector<int> > ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
        
    }

int main()
{
    vector<int> nums = {1,2,3};

    cout<<subsets(nums);

}