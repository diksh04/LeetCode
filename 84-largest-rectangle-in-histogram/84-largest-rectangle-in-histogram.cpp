class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int>leftBound(n,0);
        stack<int>stac;
        stac.push(0);
        leftBound[0]=-1;
        for(int i=1;i<n;i++)
        {
             while(stac.size()>0 && heights[i]<=heights[stac.top()])
             {
                 stac.pop();
             }
            if(stac.size()==0)
            {
                leftBound[i]=-1;
            }
            else
            {
                leftBound[i]=stac.top();
            }
            stac.push(i);
        }
          vector<int>rightBound(n,0);
          stack<int>st;
          st.push(n-1);
          rightBound[n-1]=n;
          for(int i=n-2;i>=0;i--)
          {
            while(st.size()>0 && heights[i]<=heights[st.top()])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                rightBound[i]=n;
            }
            else
            {
                rightBound[i]=st.top();
            }
            st.push(i);
          }
        int maxArea = 0;
        for(int i=0;i<n;i++)
        {
            int width = rightBound[i]-leftBound[i]-1;
            int area = heights[i] * width;
            if(area>maxArea)
            {
                maxArea = area;
            }
        }
        return maxArea;
    }
};