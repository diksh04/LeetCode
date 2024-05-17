class Solution {
public:
    bool helper(int idx,string &s,unordered_set<string>& st,vector<int>& dp)
    {
        if(idx==s.size()) return true;
        if(dp[idx]!=-1) return dp[idx];
        
        for(int i=idx;i<s.size();i++)
        {
            if(st.count(s.substr(idx,i+1-idx)) && helper(i+1,s,st,dp))
            {
                return dp[idx]  = true; 
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        return helper(0,s,st,dp);
    }
};