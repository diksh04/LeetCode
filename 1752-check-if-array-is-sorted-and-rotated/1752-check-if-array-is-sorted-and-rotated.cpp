class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        // 1 2 3 4 5
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])
            {
                count++;
            }
        }
        if(nums[nums.size()-1] > nums[0])
        {
            count++;
        }
        return count <= 1;
    }
};