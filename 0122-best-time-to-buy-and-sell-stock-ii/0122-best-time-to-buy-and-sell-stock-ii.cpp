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
        vector<int>ahead(2,0),curr(2,0);
        ahead[0] = ahead[1] = 0;
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                long profit = 0;
                if(buy == 1)
                {
                    profit = max(-prices[i]+ahead[0],ahead[1]);
                }
                else
                {
                    profit = max(prices[i]+ahead[1],ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};