vector<int> findDuplicates(vector<int>& nums) {

        unordered_map<int,int> count;

        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }

        vector<int> ans;

        for(int i=1;i<=nums.size();i++)
        {
            if(count[i] == 2)
            {
                ans.push_back(i);
            }
        }
        
        return ans;
    }