class Solution {
public:
    int maxDepth(string s) {
        
        int cnt = 0,maxi = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                cnt++;
            }
            else if(s[i]==')')
            {
                maxi = max(maxi,cnt);
                cnt--;
            }
        }
        return maxi;
    }
};