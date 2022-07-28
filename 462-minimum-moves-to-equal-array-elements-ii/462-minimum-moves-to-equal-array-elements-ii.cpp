class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int steps = 0;
        int i = 0,j = n-1;
        while(i<j)
        {
            steps+=abs(nums[i]-nums[j]);
            i++;
            j--;
        }
        return steps;
    }
};
