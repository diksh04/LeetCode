class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt = 1;
        int len = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                cnt++;
            }
            else
            {
                len = max(len,cnt);
                cnt = 1;
            }
        }
        len = max(len,cnt);
        cnt = 1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])
            {
                cnt++;
            }
            else
            {
                len = max(len,cnt);
                cnt = 1;
            }
        }
        len = max(len,cnt);
        return len;
    }
};