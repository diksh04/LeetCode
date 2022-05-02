class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n);
        stack<int>st;
        ans[n-1]=0;
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(st.size()>0 && temperatures[i]>=temperatures[st.top()])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                ans[i]=0;   
            }
            else
            {
                ans[i]=st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }
};