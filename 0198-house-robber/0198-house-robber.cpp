class Solution {
public:
    int helper(int idx,vector<int>& nums,vector<int>& dp)
    {
        if(idx<0) return 0;
        if(idx==0)
        {
            return nums[idx];
        }
        if(dp[idx]!=-1) return dp[idx];
        int pick = nums[idx] + helper(idx-2,nums,dp);
        int notpick = 0 + helper(idx-1,nums,dp);
        return dp[idx] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0,prev=nums[0];
        for(int i=1;i<n;i++)
        {
            int pick = nums[i];
            if(i>1)
            {
                pick+=prev2;
            }
            int notpick = prev + 0;
            int curr = max(pick,notpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};