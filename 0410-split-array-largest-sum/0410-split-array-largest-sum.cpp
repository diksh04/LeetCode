class Solution {
public:
    int helper(vector<int>& nums,int maxSum)
    {
        int split = 1,sum= 0;
        for(auto it:nums)
        {
            if(sum+it<=maxSum)
            {
                sum+=it;
            }
            else
            {
                split++;
                sum = it;
            }
        }
        return split;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int split = helper(nums,mid);
            if(split > k)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return low;
    }
};