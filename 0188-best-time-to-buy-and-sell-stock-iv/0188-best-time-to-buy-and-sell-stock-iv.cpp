class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int transNo = 2*k-1;transNo>=0;transNo--)
            {
                int profit = 0;
                if(transNo%2==0)//buy
                {
                    dp[idx][transNo] = max(-prices[idx]+dp[idx+1][transNo+1],
                               dp[idx+1][transNo]);
                }
                else
                    dp[idx][transNo] = max(prices[idx]+dp[idx+1][transNo+1],dp[idx+1][transNo]);
            }
        }
        return dp[0][0];
    }
};