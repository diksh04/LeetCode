class Solution {
public:
    vector<int>getNSL(vector<int>& arr,int n)
    {
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
                while(!st.empty() && arr[i]<=arr[st.top()])
                {
                    st.pop();
                }
                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int>getNSR(vector<int>& arr,int n)
    {
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
                while(!st.empty() && arr[i] < arr[st.top()])
                {
                    st.pop();
                }
                ans[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int>getNGL(vector<int>& arr,int n)
    {
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
                while(!st.empty() && arr[i] >= arr[st.top()])
                {
                    st.pop();
                }
                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int>getNGR(vector<int>& arr,int n)
    {
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
                while(!st.empty() && arr[i] > arr[st.top()])
                {
                    st.pop();
                }
                ans[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return ans;
    }
    long long subArrayMin(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>NSL = getNSL(nums,n);
        vector<int>NSR = getNSR(nums,n);
        long long sum = 0;
        for(int i=0;i<n;i++)
        {
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;
            long long totalWays = ls * rs;
            long long totalSum = totalWays * nums[i];
            sum = sum + totalSum;
        }
        return sum;
    }
    long long subArrayMax(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>NGL = getNGL(nums,n);
        vector<int>NGR = getNGR(nums,n);
        long long sum = 0;
        for(int i=0;i<n;i++)
        {
            long long ls = i - NGL[i];
            long long rs = NGR[i] - i;
            long long totalWays = ls * rs;
            long long totalSum = totalWays * nums[i];
            sum = sum + totalSum;
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return subArrayMax(nums) - subArrayMin(nums);
    }
};
// 1 2 3
//     [1] [2] [3] [1,2] [2,3] [1,2,3]
// max  1 + 2 + 3 + 2   +  3   + 1 -> sum of subarray max
// min  -1 -2  -3   -1    -2     -1    -> sum of subarray min
// long long ans = max - min;