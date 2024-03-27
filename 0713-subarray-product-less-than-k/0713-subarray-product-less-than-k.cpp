class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0,j = 0;
        if(k<=1) return 0;
        int cnt = 0;
        int prod = 1;
        while(j<nums.size())
        {
            prod*=nums[j];
            while(prod >= k && i<nums.size())
            {
                prod/=nums[i];
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
};