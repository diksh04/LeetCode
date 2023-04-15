class Solution {
public:
    int helper(int idx,vector<vector<int>>& piles,vector<vector<int>>& dp,int k)
    {
        if(idx>=piles.size() || k<=0)
        {
            return 0;
        }
        if(dp[idx][k]!=-1)
        {
            return dp[idx][k];
        }
        int fur = helper(idx+1,piles,dp,k);
        int curr = 0;
        for(int i=0;i<piles[idx].size() && i<k;i++)
        {
            curr += piles[idx][i]; 
            fur = max(fur, curr+helper(idx+1,piles,dp,k-i-1));
        }
        return dp[idx][k]=fur;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>>dp(piles.size(),vector<int>(k+1,-1));
        return helper(0,piles,dp,k);
    }
};