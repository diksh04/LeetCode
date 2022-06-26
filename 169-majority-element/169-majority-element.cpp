class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n==1)
        {
            return nums[0];
        }
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                count=1;
            }
            else
            {
                count++;
            }
            if(count>n/2)
            {
                ans=nums[i];
            }
        }
        return ans;
    }
};