class Solution {
public:
    int kadanes(vector<int>& nums)
    {
        int n = nums.size();
        int curr = 0;
        int mx = INT_MIN;
        for(int i=0;i<n;i++)
        {
            curr+=nums[i];
            if(curr>mx)
            {
                mx = curr;
            }
            if(curr<0)
            {
                curr = 0;
            }
        }
        return mx;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans1 = kadanes(nums);
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            nums[i]*=-1;
        }
        int ans2 = kadanes(nums);
        if(ans2+sum==0)
        {
            return ans1;
        }
        return max(ans1,ans2+sum);
    }
};