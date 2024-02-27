class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int>front(2,0),curr(2,0);
        for(int idx=n-1;idx>=0;idx--)
        {
            curr[1] = max(-prices[idx]+front[0],
                                  front[1]);
            curr[0] = max(prices[idx]-fee+front[1],
                              front[0]);
            front = curr;
        }
        return front[1];
    }
};