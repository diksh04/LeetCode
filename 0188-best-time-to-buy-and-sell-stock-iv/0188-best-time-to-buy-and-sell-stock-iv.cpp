class Solution {
public:
    int helper(int idx,int transNo,int k,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(idx==prices.size() || transNo == 2*k)
        {
            return 0;
        }
        if(dp[idx][transNo]!=-1) return dp[idx][transNo];
        int profit = 0;
        if(transNo%2==0)//buy
        {
            return dp[idx][transNo] = max(-prices[idx]+helper(idx+1,transNo+1,k,prices,dp),
                      0 + helper(idx+1,transNo,k,prices,dp));
        }
        else
            return dp[idx][transNo] = max(prices[idx]+helper(idx+1,transNo+1,k,prices,dp),
                      0 + helper(idx+1,transNo,k,prices,dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,-1));
        return helper(0,0,k,prices,dp);
    }
};