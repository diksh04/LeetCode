class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long ans = 0;
        bool minFound = false,maxFound = false;
        int start = 0,minStart=0,maxStart=0;
        for(int i=0;i<nums.size();i++)
        {
            int val = nums[i];
            if(val < minK || val > maxK)
            {
                minFound = false;
                maxFound = false;
                start = i+1;
            }
            if(val == minK)
            {
                minFound = true;
                minStart = i;
            }
            if(val == maxK)
            {
                maxFound = true;
                maxStart = i;
            }
            if(minFound && maxFound)
            {
                ans+=(min(minStart,maxStart) - start+1);
            }
        }
        return ans;
    }
};