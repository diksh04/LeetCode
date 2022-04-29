class Solution {
public:
    int minMoves(vector<int>& nums) {
        int x = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            x = min(x,nums[i]);
        }
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            count+=nums[i]-x;
        }
        return count;
    }
};