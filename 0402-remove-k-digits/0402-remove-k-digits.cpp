class Solution {
public:
    string removeKdigits(string num, int k) {
//         intutiton: idea is simple if nums[i] < st.top() we pop that elem from stack
        stack<char>st;
        for(int i=0;i<num.size();i++)
        {
            while(!st.empty() && k>0 && num[i]-'0' < st.top()-'0')
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty() && k>0)
        {
            k--;
            st.pop();
        }
        string ans = "";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int j = 0;
        while(ans[j]=='0' && ans.size()>1)
        {
            j++;
        }
        if(j!=0 && j<ans.size())
        {
            return ans.substr(j);
        }
        if(j==ans.size()) return "0";
        return ans;
    }
};
