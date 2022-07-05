class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++)
        {
            freq[t[i]-'a']--;
        }
        int ans = 0;
        for(int i=0;i<26;i++)
        {
            ans+=abs(freq[i]);
        }
        return ans;
    }
};