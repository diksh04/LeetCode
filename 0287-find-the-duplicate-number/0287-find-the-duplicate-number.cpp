class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i])==s.end())
            {
                s.insert(nums[i]);
            }
            else
            {
                return nums[i];
            }
        }
        return -1;
    }
};