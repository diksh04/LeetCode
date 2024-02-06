class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans = "";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                if(!st.empty())
                {
                    ans+='(';
                }
                st.push('(');
            }
            else
            {
                st.pop();
                if(!st.empty())
                {
                    ans+=')';
                }
            }
        }
        return ans;
    }
};