class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' && count==0)
            {
                count++;
            }
            else if(s[i]=='(' && count>=1)
            {
                ans+='(';
                count++;
            }
            else if(s[i]==')' && count>1 )
            {
                ans+=')';
                count--;
            }
            else if(s[i]==')' && count==1)
            {
                count--;
            }
        }
        return ans;
    }
};