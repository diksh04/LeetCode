class Solution {
public:
    int helper(vector<int>& nums,int target,vector<int>& dp)
    {
        if(target==0)
        {
            return 1;
        }
        if(target<0)
        {
            return 0;
        }
        if(dp[target]!=-1)
        {
            return dp[target];
        }
        int res = 0;
        for(auto it:nums)
        {
            if(it<=target)
            {
                res+=helper(nums,target-it,dp);
            }
        }
        return dp[target] = res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return helper(nums,target,dp);
    }
};