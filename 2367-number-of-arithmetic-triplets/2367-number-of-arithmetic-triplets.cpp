class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i]-diff)!=s.end() && s.find(nums[i]+diff)!=s.end())
            {
                count++;
            }
        }
        return count;
    }
};