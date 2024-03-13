class Solution {
public:
    int pivotInteger(int n) {
        vector<int>prefix(n+1),suffix(n+1);
        prefix[1] = 1;
        suffix[n] = n;
        for(int i=2;i<=n;i++)
        {
            prefix[i] = prefix[i-1] + i;
        }
        for(int i=n-1;i>=1;i--)
        {
            suffix[i] = suffix[i+1] + i;
        }
        for(int i=1;i<=n;i++)
        {
            if(prefix[i]==suffix[i])
            {
                return i;
            }
        }
        return -1;
    }
};
//1  3 6 10 15 21 28 36
// 21 15 8                   