class Solution {
public:
//     {1,2,3,2,4,2}
    vector<int>getNSL(vector<int>& arr)
    {
        int n = arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                while(!st.empty() && arr[st.top()] >= arr[i])
                {
                    st.pop();
                }
                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int>getNSR(vector<int>& arr)
    {
        int n = arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                ans[i] = n;
            }
            else
            {
                while(!st.empty() && arr[st.top()] > arr[i])
                {
                    st.pop();
                }
                ans[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>NSL = getNSL(arr);//next smaller to left
        vector<int>NSR = getNSR(arr);//next smaller elem to right
        long long sum = 0;
        int M = 1e9+7;
        for(int i=0;i<n;i++)
        {
            long long ls = i - NSL[i];//left mai kitne elems honge
            long long rs = NSR[i] - i;//right mai kitne honge
            long long totalWays = ls*rs;
//             totalWays subarray honge jinka minimum arr[i]
            
            long long totalSum = arr[i]*totalWays;
            sum=(sum+totalSum)%M;
        }
        return sum;
    }
};