class Solution {
public:
    int helper(int i,string word1,int j,string word2,vector<vector<int>>& dp)
    {
        if(i<0) return j+1;//word1 is exhausted,insert all chars of word2
        if(j<0) return i+1;//word2 is exhuasted,delete all chars of word1
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i] == word2[j])
        {
            return dp[i][j] = helper(i-1,word1,j-1,word2,dp);
        }
        else
        {
            int insertion = 1 + helper(i,word1,j-1,word2,dp);
            int deletion =  1 + helper(i-1,word1,j,word2,dp);
            int replace = 1 + helper(i-1,word1,j-1,word2,dp);
            return dp[i][j] = min({insertion,deletion,replace});
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(n-1,word1,m-1,word2,dp);
    }
};