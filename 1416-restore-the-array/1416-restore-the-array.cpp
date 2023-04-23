class Solution {
public:
    int helper(string &s,int &k,int idx,vector<int>& dp)
    {
        if(idx==s.size())
        {
            return 1;
        }
        if(s[idx]=='0')
        {
            return 0;
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        long ans=0,num = 0;
        for(int j=idx;j<s.size();j++)
        {
            num = num*10 + s[j]-'0';
            if(num > k)
            {
                break;
            }
            ans+=helper(s,k,j+1,dp);
            ans%=1000000007;
        }
        return dp[idx] = ans;
    }
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(), -1);
        return helper(s, k, 0, dp);
    }
};