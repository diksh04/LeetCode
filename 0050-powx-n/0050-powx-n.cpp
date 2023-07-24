class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
        {
            return 1;
        }
        long newn = n;
        if(newn<0)
        {
            newn = -newn;
            x = 1/x;
        }
        double xpnb2 = myPow(x,newn/2);
        double xpn = xpnb2*xpnb2;
        if(newn%2==1)
        {
            xpn = x*xpn;
        }
        return xpn;
    }
};