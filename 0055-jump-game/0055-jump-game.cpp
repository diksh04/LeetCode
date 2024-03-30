class Solution {
public:
    bool helper(int idx,vector<int>& nums,vector<int>& dp)
    {
        if(idx==nums.size()-1) return true;
        if(dp[idx]!=-1) return dp[idx];
        int reach = idx + nums[idx];
        
        for(int k = idx+1;k<=reach;k++)
        {
            if(helper(k,nums,dp)) 
            {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return helper(0,nums,dp);
    }
};