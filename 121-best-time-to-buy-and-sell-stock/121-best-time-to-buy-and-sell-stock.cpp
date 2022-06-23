class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int maxProfit = 0;
        for(int i=1;i<prices.size();i++)
        {
            mn = min(mn,prices[i]);
            int profit = prices[i]-mn;
            maxProfit = max(profit,maxProfit);
        }
        return maxProfit;
    }
};