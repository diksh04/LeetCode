class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return nums[n-k];
    }
};
//1 2 3 4 5 6
//1 2 2 3 3 4 5 5 6