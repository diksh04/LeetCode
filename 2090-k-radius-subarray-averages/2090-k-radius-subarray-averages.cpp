class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n,-1);
        if(k == 0)
        {
            return nums;
        }
        if(n < 2*k+1)
        {
            return ans;
        }
        vector<long long>prefix(n,0);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1]+nums[i];
        }
        for(int i=k;i<=n-k-1;i++)
        {
            int leftIdx = i-k;
            int rightIdx = i+k;
            long long sum = prefix[rightIdx];
            if(leftIdx>0)
            {
                sum-=prefix[leftIdx-1];
            }
            ans[i] = sum/(2*k+1);
        }
        return ans;
    }
};