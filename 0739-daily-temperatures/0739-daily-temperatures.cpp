class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n);
        stack<int>st;
        st.push(n-1);
        ans[n-1] = 0;
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && temperatures[i]>=temperatures[st.top()])
            {
                st.pop();
            }
            if(st.empty())
            {
                ans[i] = 0;
            }
            else
            {
                ans[i] = st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }
};