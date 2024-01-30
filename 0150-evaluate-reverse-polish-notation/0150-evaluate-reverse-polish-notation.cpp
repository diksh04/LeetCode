class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto ch:tokens)
        {
            if(ch=="+" || ch=="-" || ch=="*" || ch=="/")
            {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                if(ch == "+")
                {
                    val1+=val2;
                }
                if(ch=="-")
                {
                    val1=val2-val1;
                }
                if(ch=="*")
                {
                    val1*=val2;
                }
                if(ch=="/")
                {
                    val1=val2/val1;
                }
                st.push(val1);
            }
            else
            {
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};