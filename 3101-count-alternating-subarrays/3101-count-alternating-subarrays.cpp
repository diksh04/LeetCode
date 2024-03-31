class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long int cnt = 1;
        long long int ans = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
            {
                cnt++;
            }
            else
            {
                ans = ans + (cnt*(cnt+1))/2;
                cnt = 1;
            }
        }
        ans = ans + (cnt*(cnt+1))/2;
        return ans;
    }
};