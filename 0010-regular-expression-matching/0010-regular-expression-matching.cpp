class Solution {
public:
    int helper(int i,int j,string s,string p,vector<vector<int>>& dp)
    {
        if(i==0 && j == 0){
            return true;
        }
        else if(j==0 && i>0){
            return false;
        }
        else if(j>0 && i==0){
            if(p[j-1]=='*') return dp[i][j] = helper(i,j-2,s,p,dp);

            else return 0;
        }
        else if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i-1] == p[j-1] || p[j-1] == '.'){
            return dp[i][j] = helper(i-1,j-1,s,p,dp);
        }
        else if(p[j-1] == '*')
        {
            int with_star = 0, without_star = 0;

				if(s[i-1] == p[j-2] || p[j-2] == '.')
					with_star = helper(i-1, j, s, p, dp);

				without_star = helper(i,j-2,s,p,dp);
				return dp[i][j] = with_star || without_star;
        }
        else return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(),m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(n,m,s,p,dp);
    }
};