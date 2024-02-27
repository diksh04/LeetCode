class Solution {
public:
    int helper(int idx,int buy,vector<int>& prices,int fee,vector<vector<int>>& dp)
    {
        if(idx==prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            return dp[idx][buy] = max(-prices[idx]+helper(idx+1,0,prices,fee,dp),
                                  helper(idx+1,1,prices,fee,dp));
        }
        return dp[idx][buy] = max(prices[idx]-fee+helper(idx+1,1,prices,fee,dp),
                              helper(idx+1,0,prices,fee,dp));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return helper(0,1,prices,fee,dp);
    }
};