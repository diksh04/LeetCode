class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1)
        {
            return s;
        }
        int max_len=1;
        int st=0,end=0;
//         odd length
        for(int i=0;i<n-1;i++)// babad ,i=b
                            //   01234
        {
            int l=i,r=i;// l=b,r=b
            while(l>=0 && r<n )
            {
                if(s[l]==s[r])
                {
                    l--;// -1 
                    r++;// 3
                }
                else
                {
                    break;
                }
            }
            int len = r-l-1;
             if(len>max_len)
             {
                 max_len = len;
                 st=l+1;
                 end=r-1;
             }
        }
        
        //even length
        for(int i=0;i<n-1;i++)
        {
            int l=i,r=i+1;
            while(l>=0 && r<n )
            {
                if(s[l]==s[r])
                {
                    l--;
                    r++;
                }
                else
                {
                    break;
                }
            }
            int len = r-l-1;
             if(len>max_len)
             {
                 max_len = len;
                 st=l+1;
                 end=r-1;
             }
        }
        return s.substr(st,max_len);
    }
};