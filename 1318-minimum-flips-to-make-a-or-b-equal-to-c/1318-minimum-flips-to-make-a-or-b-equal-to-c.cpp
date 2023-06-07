class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while(a>0 || b>0 || c>0) // a -> 010 , b-> 110,c-> 101
        {
            int rem1 = a & 1;//last bit of a i.e 0
            int rem2 = b & 1;//last bit of b i.e 0
            int rem3 = c & 1;//last bit of c i.e 1
            
            if((rem1 | rem2 )!=rem3)
            {
                if(rem3==1)
                {
                    flips++;
                }
                else
                {
                    flips+=(rem1+rem2);
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return flips;
    }
};