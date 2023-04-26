class Solution {
public:
    int countAsterisks(string s) {
        int astricks = 0;
        int bars = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='|')
            {
                bars++;
            }
            if(bars%2==0 && s[i]=='*')
            {
                astricks++;
            }
        }
        return astricks;
    }
};