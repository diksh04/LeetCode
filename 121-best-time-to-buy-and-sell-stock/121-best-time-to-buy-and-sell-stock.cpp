class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>aux(prices.size(),0);
        int mx = INT_MIN;
        for(int i=prices.size()-1;i>=0;i--)
        {
            mx=max(mx,prices[i]);
            aux[i]=mx;
        }
        int profit = 0;
        for(int i=0;i<prices.size();i++)
        {
            profit = max(profit,aux[i]-prices[i]);
        }
        return profit;
    }
};