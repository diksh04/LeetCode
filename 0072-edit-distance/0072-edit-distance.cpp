class Solution {
public:
    int helper(int i,int j,string& word1,string &word2,vector<vector<int>>& dp)
    {
        if(i<0) return j+1;//all will be insert operations
        if(j<0) return i+1;//all will be delete operations
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j])
        {
            return dp[i][j] = helper(i-1,j-1,word1,word2,dp);
        }
        else
        {
            // insert delete replace
            return dp[i][j] = 1 + min({
                                     helper(i,j-1,word1,word2,dp),
                                     helper(i-1,j,word1,word2,dp),
                                     helper(i-1,j-1,word1,word2,dp)
                                      });
        }
            
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(),m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,word1,word2,dp);
    }
};