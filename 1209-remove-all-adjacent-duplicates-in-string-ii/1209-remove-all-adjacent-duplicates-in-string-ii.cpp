class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0; i<s.size(); i++){
            if(st.empty() || st.top().first != s[i]) 
            {
                st.push({s[i],1});
            }
            else
            {
                auto prev = st.top();
                st.pop();
                st.push({s[i], prev.second+1});
            }
            if(st.top().second==k) 
            {
                st.pop();
            }
        }
        string str = "";
        while(st.size()>0)
        {
            auto curr = st.top();
            st.pop();
            while(curr.second!=0)
            {
                str+=curr.first;
                curr.second--;
            }
        }
        string ans="";
        for(int i=str.size()-1;i>=0;i--)
        {
            ans+=str[i];
        }
        return ans;
    }
};