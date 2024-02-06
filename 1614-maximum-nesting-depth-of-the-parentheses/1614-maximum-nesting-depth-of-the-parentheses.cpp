class Solution {
public:
    int maxDepth(string s) {
        int cmax = 0;
        int maxi = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                cmax++;
                maxi = max(maxi,cmax);
            }
            else if(s[i]==')')
            {
                cmax--;
            }
        }
        return maxi;
    }
};