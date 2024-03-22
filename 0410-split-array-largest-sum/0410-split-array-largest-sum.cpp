class Solution {
public:
    int countSplit(vector<int>& nums,int maxSum,int k)
    {
        int split = 1,sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(sum+nums[i] <= maxSum)
            {
                sum+=nums[i];
            }
            else
            {
                split++;
                sum = nums[i];
            }
        }
        return split;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int split = countSplit(nums,mid,k);
            if(split > k)
            {
                low = mid+1;
            }
            else high = mid-1;
        }
        return low;
    }
};