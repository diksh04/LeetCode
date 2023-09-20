class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0 ,n = nums.size();
        int i = 0,j = 0;
        int tsum = accumulate(nums.begin(),nums.end(),0);
        tsum-=x;
        if(tsum == 0)
        {
            return n;
        }
        int len = 0;
        while(j<nums.size())
        {
            sum+=nums[j];
            while(i<n && sum > tsum)
            {
                sum-=nums[i];
                i++;
            }
            if(sum == tsum)
            {
                len = max(len,j-i+1);
            }
            j++;
        }
        return len == 0?-1:n-len;
    }
};