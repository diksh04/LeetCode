class Solution {
public:
    int helper(int idx,int prev,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(idx==nums.size()) return 0;
        
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        
        int notTake = 0 + helper(idx+1,prev,nums,dp);
        int take = 0;
        if(prev == -1 || nums[idx] > nums[prev])
        {
            take = 1 + helper(idx+1,idx,nums,dp);
        }
        return dp[idx][prev+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
       vector<int>next(n+1,0),curr(n+1,0);
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int prev=idx-1;prev>=-1;prev--)
            {
                int notTake = 0 + next[prev+1];
                int take = 0;
                if(prev == -1 || nums[idx] > nums[prev])
                {
                    take = 1 +next[idx+1];
                }
                curr[prev+1] = max(take,notTake);
            }
            next = curr;
        }
        return next[0];
    }
};