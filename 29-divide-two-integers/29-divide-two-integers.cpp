class Solution {
public:
    int divide(long long int dividend,long long int divisor) {
       long long ans= dividend/divisor;
        if(ans > INT_MAX)
        {
            return INT_MAX;
        }
        else if(ans < INT_MIN)
        {
            return INT_MIN;
        }
        return ans;
    }
};