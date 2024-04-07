class Solution {
public:
    string getSmallestString(string s, int k) {
        for(int i=0;i<s.size();i++)
        {
            int forwardCnt = s[i] - 'a';
            int backwardCnt = 'z' - s[i] + 1;
            if(min(forwardCnt,backwardCnt)<=k)
            {
                k-=min(forwardCnt,backwardCnt);
                s[i] = 'a';
            }
            else
            {
                s[i]-=k;
                k=0;
            }
            if(k==0) return s;
        }
        return s;
    }
};
// xaxcd
// 3 1 