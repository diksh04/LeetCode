class Solution {
public:
    bool helper(int i,int j,string &s,string &p,vector<vector<int>>& dp)
    {
        if(i==0 && j==0) return true;
        if(i>0 && j==0) return false;
        if(i==0 && j>0)
        {
            for(int ii=1;ii<=j;ii++)
            {
                if(p[ii-1]!='*')
                {
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==p[j-1] || p[j-1]=='?') 
        {
            return dp[i][j] = helper(i-1,j-1,s,p,dp);
        }
        else if(p[j-1]=='*')
        {
            bool val1 = helper(i,j-1,s,p,dp);//we are not matching anything with *
            bool val2 = helper(i-1,j,s,p,dp);//we are matching char in s with *  in p
            return dp[i][j] = val1 | val2;
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(),m = p.size();
        vector<bool>prev(m+1,false),curr(m+1,false);
        prev[0] = true;
        for(int j=1;j<=m;j++)
        {
            bool flag = true;
            for(int ii=1;ii<=j;ii++)
            {
                if(p[ii-1]!='*')
                {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }
        for(int i=1;i<=n;i++)
        {
            curr[0] = false;
            for(int j=1;j<=m;j++)
            {
                    if(s[i-1]==p[j-1] || p[j-1]=='?') 
                    {
                        curr[j] = prev[j-1];
                    }
                    else if(p[j-1]=='*')
                    {
                        bool val1 = curr[j-1];//we are not matching anything with *
                        bool val2 = prev[j];//we are matching char in s with *  in p
                        curr[j] = val1 | val2;
                    }
                    else curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];
    }
};