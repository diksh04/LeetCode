class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>nge(n,0);
        stack<int>st;
        st.push(n-1);
        nge[n-1]=n;
         for(int i=n-2;i>=0;i--)
          {
            while(st.size()>0 && nums[i]>nums[st.top()])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                nge[i]=n;
            }
            else
            {
                nge[i]=st.top();
            }
            st.push(i);
          }
        int j=0;
        vector<int>ans;
        for(int i=0;i<=n-k;i++)
        {
            if(j<i)
            {
                j=i;
            }
            while(nge[j] < i+k)
            {
                j=nge[j];
            }
            ans.push_back(nums[j]);
        }
        return ans;
    }
};