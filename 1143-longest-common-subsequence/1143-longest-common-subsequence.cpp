class Solution {
public:
    int helper(int idx,string &text1,int jdx,string &text2,vector<vector<int>>& dp)
    {
        if(idx==0 || jdx==0)
        {
            return 0;
        }
        if(dp[idx][jdx]!=-1)
        {
            return dp[idx][jdx];
        }
        if(text1[idx-1]==text2[jdx-1])
        {
            return dp[idx][jdx] = 1 + helper(idx-1,text1,jdx-1,text2,dp);
        }
        return dp[idx][jdx] = max(helper(idx-1,text1,jdx,text2,dp),helper(idx,text1,jdx-1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(),m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(n,text1,m,text2,dp);
    }
};