class Solution {
public:
    bool helper(int idx,int target,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(target==0) return true;
        if(idx==0) return nums[0] == target;
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool notpick = helper(idx-1,target,nums,dp);
        bool pick = false;
        if(nums[idx]<=target)
        {
            pick = helper(idx-1,target-nums[idx],nums,dp);
        }
        return dp[idx][target] = notpick | pick;
    }
    bool canPartition(vector<int>& nums) {
        int tsum = accumulate(nums.begin(),nums.end(),0);
        if(tsum%2!=0) return false;
        int sum = tsum/2;
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return helper(n-1,sum,nums,dp);
    }
};