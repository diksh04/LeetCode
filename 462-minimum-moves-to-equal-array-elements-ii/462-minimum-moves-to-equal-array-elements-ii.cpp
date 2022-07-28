class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
//         find the median
        int median = n%2==0 ? (nums[n/2]+nums[n/2-1])/2 : nums[n/2];
         int steps = 0;
        for(int num : nums)
        {
            steps+=abs(num-median);
            
        }
        return steps;
    }
};