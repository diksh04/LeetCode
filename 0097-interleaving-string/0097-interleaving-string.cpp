class Solution {
public:
    int m,n,N;
    bool helper(int i,int j,string s1,string s2,string s3,vector<vector<int>>& dp)
    {
        if(i==m && j==n && i+j==N)
        {
            return true;
        }
        if(i+j>=N)
        {
            return false;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        bool result = false;
        if(s1[i]==s3[i+j])
        {
            result = helper(i+1,j,s1,s2,s3,dp);
        }
        if(result == true)
        {
            return dp[i][j]= result;
        }
        if(s2[j]==s3[i+j])
        {
            result = helper(i,j+1,s1,s2,s3,dp);
        }
        return dp[i][j] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
//         TC = O(n*m) since k = i+j at every point
        m = s1.size(),n = s2.size(),N = s3.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(0,0,s1,s2,s3,dp);
    }
};