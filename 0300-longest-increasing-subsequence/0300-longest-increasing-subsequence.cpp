class Solution {
public:
    int helper(int idx,int prevIdx,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(idx==nums.size()) return 0;
        if(dp[idx][prevIdx+1]!=-1) return dp[idx][prevIdx+1];
        int notTake = 0 + helper(idx+1,prevIdx,nums,dp);
        int take = 0;
        if(prevIdx==-1 || nums[idx]>nums[prevIdx])
        {
            take = 1 + helper(idx+1,idx,nums,dp);
        }
        return dp[idx][prevIdx+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //we can't store at -1 we will coordinate shift         
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int prevIdx=idx-1;prevIdx>=-1;prevIdx--)
            {
                int notTake = 0 + dp[idx+1][prevIdx+1];
                int take = 0;
                if(prevIdx==-1 || nums[idx]>nums[prevIdx])
                {
                    take = 1 + dp[idx+1][idx+1];
                }
                dp[idx][prevIdx+1] = max(take,notTake);
            }
        }
        return dp[0][0];
    }
};