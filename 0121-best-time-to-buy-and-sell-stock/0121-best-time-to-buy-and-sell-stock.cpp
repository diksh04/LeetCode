class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = INT_MIN;
        int mn = INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            mn = min(mn,prices[i]);
            profit = max(profit,prices[i]-mn);
        }
        return profit;
    }
};