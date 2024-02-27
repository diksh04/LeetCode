class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        int maxi = 1;
        for(int idx=0;idx<n;idx++)
        {
            for(int prev=0;prev<idx;prev++)
            {
                if(nums[prev]<nums[idx])
                {
                    dp[idx] = max(1+dp[prev],dp[idx]);
                }
            }
            maxi = max(maxi,dp[idx]);
        }
        return  maxi;
    }
};