class Solution {
public:
    int helper(vector<int>& satisfaction,int i,int j,vector<vector<int>>& dp)
    {
        if(i==satisfaction.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int pick = j*satisfaction[i] + helper(satisfaction,i+1,j+1,dp);
        int notpick = helper(satisfaction,i+1,j,dp);
        dp[i][j] = max(pick,notpick);
        return dp[i][j];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(satisfaction,0,1,dp);
    }
};