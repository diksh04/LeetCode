class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        vector<int>nge(n,0);
        nge[n-1] = 0;
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            if(!st.empty() && arr[i]<arr[st.top()])
            {
                nge[i] = st.top()-i;
                st.push(i);
            }
            else
            {
                while(!st.empty() && arr[i]>=arr[st.top()])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    nge[i] = 0;
                }
                else nge[i] = st.top()-i;
                st.push(i);
            }
        }
        return nge;
    }
};