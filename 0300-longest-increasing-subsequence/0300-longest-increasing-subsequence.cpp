class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int idx=n-1;idx>=0;idx--)
    {
        for(int prev_idx=idx-1;prev_idx>=-1;prev_idx--)
        {
            int len = 0 + dp[idx+1][prev_idx+1];
            if(prev_idx == -1 || nums[idx] > nums[prev_idx])
            {
                len = max(len,1+dp[idx+1][idx+1]);
            }
            dp[idx][prev_idx+1] = len;
        }
    }
    return dp[0][-1+1];
    }
};