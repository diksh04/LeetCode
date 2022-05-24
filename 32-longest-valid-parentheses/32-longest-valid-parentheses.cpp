class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);// bottom of stack will always hold index preceding to potential start of valid parentheses
        int MAX=0;//max len
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            if(ch=='(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.size()==0)
                {
                    st.push(i);
                }
                else
                {
                    MAX = max(MAX,i-st.top());
                }
            }
        }
        return MAX;
    }
};