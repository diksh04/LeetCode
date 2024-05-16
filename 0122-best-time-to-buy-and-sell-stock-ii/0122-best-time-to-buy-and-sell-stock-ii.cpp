class Solution {
public:
    int helper(int idx,int buy,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(idx==prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        
        int profit = 0;
        if(buy)
        {
            int weBuy = -prices[idx] + helper(idx+1,0,prices,dp);
            int notBuy = helper(idx+1,1,prices,dp);
            profit = max(weBuy,notBuy);
        }
        else
        {
            int weSell = prices[idx] + helper(idx+1,1,prices,dp);
            int notSell = helper(idx+1,0,prices,dp);
            profit = max(weSell,notSell);
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,1,prices,dp);
    }
};