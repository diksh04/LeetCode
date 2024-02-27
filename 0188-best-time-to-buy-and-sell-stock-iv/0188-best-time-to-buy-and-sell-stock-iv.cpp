class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int>ahead(2*k+1,0);
        vector<int>curr(2*k+1,0);
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int transNo = 2*k-1;transNo>=0;transNo--)
            {
                int profit = 0;
                if(transNo%2==0)//buy
                {
                    curr[transNo] = max(-prices[idx]+ahead[transNo+1],
                               ahead[transNo]);
                }
                else
                    curr[transNo] = max(prices[idx]+ahead[transNo+1],ahead[transNo]);
            }
            ahead = curr;
        }
        return ahead[0];
    }
};