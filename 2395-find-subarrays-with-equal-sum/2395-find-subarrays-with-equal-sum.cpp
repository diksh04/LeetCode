class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int>s;
            // 1 2 3 4 5
        for(int i=0;i<nums.size()-1;i++)// 2
        {
                int sum = 0;
                sum = nums[i]+nums[i+1];//3
                if(s.find(sum)!=s.end())
                {
                    return true;
                }
                else
                {
                    s.insert(sum);
                }
        }
        return false;
    }
};