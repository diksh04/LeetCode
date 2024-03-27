class Solution {
public:
    vector<int>getNSL(vector<int>& heights,int n)
    {
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[i] <= heights[st.top()] )
            {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>getNSR(vector<int>& heights,int n)
    {
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[i] <= heights[st.top()] )
            {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left = getNSL(heights,n);
        vector<int>right = getNSR(heights,n);
        int area = INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            int lIdx = left[i];
            int rIdx = right[i];
            int width = rIdx-lIdx-1;
            int res = heights[i] * width;
            area = max(area,res);
        }
        return area;
    }
};