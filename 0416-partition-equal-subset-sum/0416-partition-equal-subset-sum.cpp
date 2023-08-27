class Solution {
public:
    bool helper(int idx,vector<int>& nums,int target,vector<vector<int>>& dp)
    {
        if(target==0)
        {
            return true;
        }
        if(idx==0)
        {
            return nums[0]==target;
        }
        if(dp[idx][target]!=-1)
        {
            return dp[idx][target];
        }
        bool notpick = helper(idx-1,nums,target,dp);
        bool pick = false;
        if(nums[idx]<=target)
        {
            pick = helper(idx-1,nums,target-nums[idx],dp);
        }
        return dp[idx][target] = pick | notpick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        // cout<<sum<<endl;
        if(sum%2!=0)
        {
            return false;
        }
        int target = sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return helper(n-1,nums,target,dp);
    }
};