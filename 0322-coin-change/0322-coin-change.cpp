class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>prev(amount+1,0),curr(amount+1,0);
        for(int t=0;t<=amount;t++)
        {
            if(t%coins[0]==0)
            {
                prev[t] = t/coins[0];
            }
            else
            {
                prev[t] = 1e9;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int t=0;t<=amount;t++)
            {
                int notpick = 0 + prev[t];
                int pick = 1e9;
                if(coins[i]<=t)
                {
                    pick = 1 + curr[t-coins[i]];
                }
                curr[t] = min(pick,notpick);
            }
            prev = curr;
        }
        if(prev[amount]>=1e9) return -1;
        return prev[amount];
    }
};