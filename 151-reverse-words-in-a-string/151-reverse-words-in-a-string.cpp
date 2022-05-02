class Solution {
public:
    string reverseWords(string s) {
        if(s.size()==0)
        {
            return s;
        }
        stack<string>st;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            string sword="";
            if(s[i]==' ')
            {
                continue;
            }
            while(i<s.size() && s[i]!=' ')
            {
                sword+=s[i];
                i++;
            }
            st.push(sword);
        }
        while(st.size()>0)
        {
            ans+=st.top();
            st.pop();
            if(st.size()!=0)
            {
                ans+=" ";
            }
        }
        return ans;
    }
};