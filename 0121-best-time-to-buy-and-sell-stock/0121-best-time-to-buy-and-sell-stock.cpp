class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxprofit = INT_MIN;
        int mn = INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            mn = min(mn,prices[i]);
            mxprofit = max(mxprofit,prices[i]-mn);
        }
        return mxprofit;
    }
};