class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int median = nums[n/2];
        if(median == k) return 0;
//         2 5 5 6 8 ,k=4
//         2 5 5 6 8 ,k=7
        long long ops = 0;
        if(median > k)
        {
            for(int i=n/2;i>=0;i--)
            {
                if(nums[i]>k) ops+=(nums[i]-k);
                else break;
            }
        }
        else
        {
            for(int i=n/2;i<n;i++)
            {
                if(nums[i]<k) ops+=(k-nums[i]);
                else break;
            }
        }
        return ops;
    }
};