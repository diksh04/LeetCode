class Solution {
public:
    bool static compare(string &s1,string &s2)
    {
        return s1.size() < s2.size();
    }
    bool checkPossible(string &s1,string &s2)
    {
        if(s1.size()!=s2.size()+1) return false;
        int i=0,j=0;
        while(i<s1.size())
        {
            if(j<s2.size() && s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else
            { 
                //abca abc
                i++;
            }
        }
        if(i==s1.size() && j==s2.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        int n = words.size();
        vector<int>dp(n,1);
        int maxi = 1;
        for(int idx=1;idx<n;idx++)
        {
            for(int prev=0;prev<idx;prev++)
            {
                if(checkPossible(words[idx],words[prev]) && dp[idx] < 1 + dp[prev])
                {
                    dp[idx] = 1 + dp[prev];
                }
            }
            maxi = max(maxi,dp[idx]);
        }
        return maxi;
    }
};