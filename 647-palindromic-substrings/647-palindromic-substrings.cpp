class Solution {
public:
    bool ispalindrome(string ss)
    {
        int left=0;
        int right=ss.size()-1;
        while(left<right)
        {
            char ch1=ss[left];
            char ch2=ss[right];
            if(ch1!=ch2)
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
    int countSubstrings(string s) {
        int count=0;
        
    for(int i=0;i<s.size();i++)
      {
        for(int j=1;j<=s.size()-i;j++)
        {
            string ss=s.substr(i,j);
            if(ispalindrome(ss)==true)
            {
               count++;
            }
        }
      }
        return count;
    }
   
};