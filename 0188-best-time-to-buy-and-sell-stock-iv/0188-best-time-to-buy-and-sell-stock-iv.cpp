class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>ahead(2,vector<int>(k+1,0));
        vector<vector<int>>curr(2,vector<int>(k+1,0));
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=k;cap++)
                {
                    int profit=0;
                    if(buy){
                        int webuy = -prices[idx] + ahead[0][cap];
                        int notbuy = 0 + ahead[1][cap];
                        profit = max(webuy,notbuy);
                    }
                    else
                    {
                        int wesell = prices[idx] + ahead[1][cap-1];
                        int notsell = 0 + ahead[0][cap];
                        profit = max(wesell,notsell);
                    }
                    curr[buy][cap] = profit;
                }
            }
            ahead = curr;
        }
        return ahead[1][k];
    }
};