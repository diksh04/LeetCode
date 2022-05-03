class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mn = INT_MAX,mx=INT_MIN;
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {
                mn = min(mn,nums[i]);
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])
            {
                mx=max(mx,nums[i]);
            }
        }
        if(mn==INT_MAX && mx==INT_MIN)
        {
            return 0;
        }
        int start=0;
        for(start=0;start<n;start++)
        {
            if(nums[start]>mn)
            {
                break;
            }
        }
        int end=n-1;
        for(end=n-1;end>=0;end--)
        {
            if(nums[end]<mx)
            {
                break;
            }
        }
        return end-start+1;
    }
};