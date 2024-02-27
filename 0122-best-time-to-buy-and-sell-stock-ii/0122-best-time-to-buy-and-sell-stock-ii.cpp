class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<long>front(2,0),curr(2,0);
        front[0] = front[1] = 0;
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                long profit = 0;
                if(buy){
                    //buy
                    int webuy = -prices[idx] + front[0];
                    int notbuy = 0 + front[1];
                    profit = max(webuy,notbuy);
                }
                else
                {
                    //sell
                    int wesell = prices[idx] + front[1];
                    int notsell = 0 + front[0];
                    profit = max(wesell,notsell);
                }
                curr[buy] = profit;
            }
            front = curr;
        }
        return front[1];
    }
};