class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty() || s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                st.push(s[i]);
            }
            else if(!st.empty() && s[i]==')')
            {
                if(st.top()=='(')
                {
                    st.pop();
                }
                else return false;
            }
            else if(!st.empty() && s[i]=='}')
            {
                if(st.top()=='{')
                {
                    st.pop();
                }
                else return false;
            }
            else if(!st.empty() && s[i]==']')
            {
                if(st.top()=='[')
                {
                    st.pop();
                }
                else return false;
            }
            
        }

        return st.empty();
    }
};