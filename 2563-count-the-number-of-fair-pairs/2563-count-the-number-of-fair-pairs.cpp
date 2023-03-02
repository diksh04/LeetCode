class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            int low = lower-nums[i],up = upper-nums[i];
            int lit = lower_bound(nums.begin()+i+1,nums.end(),low)-nums.begin();
            int uit = upper_bound(nums.begin()+i+1,nums.end(),up)-nums.begin();
            ans+=uit-lit;
        }
        return ans;
    }
};