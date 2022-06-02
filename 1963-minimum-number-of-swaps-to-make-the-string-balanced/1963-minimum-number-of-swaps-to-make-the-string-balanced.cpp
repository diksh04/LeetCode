class Solution {
public:
    int minSwaps(string s) {
        int count = 0;
        int n = s.size();
        int openBrac = 0,closeBrac = 0,lastInd = n-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='[')
            {
                openBrac++;
            }
            else if(s[i]==']')
            {
                closeBrac++;
            }
            if(closeBrac>openBrac)
            {
                while(s[lastInd]!='[')
                {
                    lastInd--;
                }
                swap(s[i],s[lastInd]);
                openBrac++;
                closeBrac--;
                count++;
            }
        }
        return count;
    }
};