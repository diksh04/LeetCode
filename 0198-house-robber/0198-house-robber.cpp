class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        dp[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            int notpick = dp[i-1] + 0;
            int pick = nums[i];
            if(i-2 >= 0) pick+=dp[i-2];
            dp[i] = max(pick,notpick);
        }
        return dp[n-1];
    }
};
// 1 2 3 1
// [1] --------- []
//[1,3] ---------[2]
//[1,3]