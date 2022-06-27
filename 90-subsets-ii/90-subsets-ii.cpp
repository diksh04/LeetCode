class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>& nums,int idx,vector<int>res)
    {
        if(idx==nums.size())
        {
            ans.push_back(res);
            return;
        }
        
        if(res.empty() || res.back()!=nums[idx])
        {
            helper(nums,idx+1,res);
        }
        res.push_back(nums[idx]);
        helper(nums,idx+1,res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>res;
        helper(nums,0,res);
        return ans;
    }
};