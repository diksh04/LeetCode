class Solution {
public:
    bool check(string &s1,string  &s2) //s1 > s2
    {
        if(s1.size()!=s2.size()+1)
        {
            return false;
        }
        int first = 0,second = 0;
        while(first<s1.size())
        {
            if(s1[first]==s2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }
        if(first == s1.size() && second == s2.size())
        {
            return true;
        }
        return false;
    }
    static bool cmp(string &s1,string &s2)
    {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),cmp);
        vector<int>dp(n,1);
        int maxi = 1;
        int lastIdx = 0;
        for(int idx=0;idx<n;idx++)
        {
            for(int prev=0;prev<idx;prev++)
            {
                if(check(words[idx],words[prev]) && 1+dp[prev] > dp[idx])
                {
                    dp[idx] = 1+dp[prev];
                }
            }
            if(dp[idx]>maxi)
            {
                maxi = dp[idx];
            }
        }
        return maxi;
    }
};