class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        // dp[n][buy->0/1][cap->0/1/2]  
        int n = prices.size();
        vector<vector<int>>ahead(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    int profit = 0;
                    if(buy){
                        int webuy = -prices[idx] + ahead[0][cap];
                        int notbuy = 0 + ahead[1][cap];
                        profit = max(webuy,notbuy);
                    }
                    else
                    {
                        int wesell = prices[idx] + ahead[1][cap-1];//transaction is completed therefore we sell
                        int notsell = 0 + ahead[0][cap];
                        profit = max(wesell,notsell);
                    }
                    curr[buy][cap] = profit;
                }
            }
            ahead = curr;
        }
        return ahead[1][2];
    }
};