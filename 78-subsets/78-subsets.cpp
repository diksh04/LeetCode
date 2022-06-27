class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&nums,int idx,vector<int> res)
    {
        if(idx==nums.size())
        {
            ans.push_back(res);
            return;
        }
        helper(nums,idx+1,res);
        res.push_back(nums[idx]);
        helper(nums,idx+1,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>res;
        helper(nums,0,res);
        return ans;
    }
};