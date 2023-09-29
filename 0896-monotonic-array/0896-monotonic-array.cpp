class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        // [11,11,9,4,3,3,3,1,-1,-1,3,3,3,5,5,5]
        bool inc = true,dec = true;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1]) inc = false;
            if(nums[i]<nums[i+1]) dec = false;
            if(!inc && !dec) return false;
        }
        return true;
    }
};