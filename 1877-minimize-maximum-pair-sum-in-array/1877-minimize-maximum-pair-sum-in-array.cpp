class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum = max(sum,nums[i] + nums[nums.size()-1-i]);
        }
        return sum;
        //2 3 3 5
    }
};