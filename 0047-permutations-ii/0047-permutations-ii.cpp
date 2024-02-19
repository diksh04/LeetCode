class Solution {
public:
    void helper(int idx,vector<int>& nums,vector<vector<int>>& ans)
    {
        if(idx==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        unordered_set<int>st;
        for(int i=idx;i<nums.size();i++)
        {
            if(st.find(nums[i])==st.end())
            {
                swap(nums[i],nums[idx]);
                helper(idx+1,nums,ans);
                swap(nums[i],nums[idx]);
                st.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        helper(0,nums,ans);
        return ans;
    }
};