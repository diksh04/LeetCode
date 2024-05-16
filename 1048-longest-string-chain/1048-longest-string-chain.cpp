class Solution {
public:
    static bool compare(string &a,string &b)
    {
        return a.size() < b.size();
    }
    bool helper(string &word1,string &word2)
    {
        if(word1.size()!=word2.size()+1) return false;
        int i=0,j=0;
        while(i<word1.size())
        {
            if(j<word2.size() && word1[i]==word2[j])
            {
                i++;
                j++;
            }
            else i++;
        }
        return (i==word1.size() && j==word2.size());
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        int n = words.size();
        vector<int>dp(n,1);
        int len = 1;
        for(int idx=0;idx<n;idx++)
        {
            for(int prev=0;prev<idx;prev++)
            {
                if(helper(words[idx],words[prev]) && 1 + dp[prev] > dp[idx])
                {
                    dp[idx] = 1 + dp[prev];
                }
            }
            len = max(len,dp[idx]);
        }
        return len;
    }
};