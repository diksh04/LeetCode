class Solution {
public:
    int longestContinuousSubstring(string s) {
        if(s.size()==1)
        {
            return 1;
        }
        int maxLen = 1;
        int count = 1;
        for(int i=1;i<s.size();i++)
        {
            if(((s[i-1]-'a')+1) == (s[i]-'a'))
            {
                count++;
                maxLen = max(maxLen,count);
            }
            else
            {
                count = 1;
            }
        }
        return maxLen;
    }
};