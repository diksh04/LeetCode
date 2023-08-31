class Solution {
public:
    int helper(int idx,int buy,vector<int>& prices,vector<vector<int>>& dp,int fee)
    {
        if(idx==prices.size())
        {
            return 0;
        }
        if(dp[idx][buy]!=-1)
        {
            return dp[idx][buy];
        }
        if(buy){
            return dp[idx][buy] = max(-prices[idx]+helper(idx+1,0,prices,dp,fee),0+helper(idx+1,1,prices,dp,fee));
        }
        return dp[idx][buy] = max(prices[idx]-fee+helper(idx+1,1,prices,dp,fee),helper(idx+1,0,prices,dp,fee));
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return helper(0,1,prices,dp,fee);
    }
};