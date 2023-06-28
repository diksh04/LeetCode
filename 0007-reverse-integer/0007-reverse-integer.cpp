class Solution {
public:
    int reverse(int x) {
        long long onum = x;
        long long res = 0;
        while(x!=0)
        {
            long rem = x%10;
            res = res*10 + rem;
            x/=10;
        }
        if(res < INT_MIN || res > INT_MAX)
        {
            return 0;
        }
        return res;
    }
};