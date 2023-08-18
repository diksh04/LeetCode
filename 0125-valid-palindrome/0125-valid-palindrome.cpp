class Solution {
public:
    bool check(string s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string ans = "";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                ans+=s[i];
            }
            else if(s[i]>='A' && s[i]<='Z')
            {
                ans+=tolower(s[i]);
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                ans+=s[i];
            }
        }
        // cout<<ans<<endl;
        // if(ans.size()==1)
        // {
        //     return false;
        // }
        return check(ans);
    }
};