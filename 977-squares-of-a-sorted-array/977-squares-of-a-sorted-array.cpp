class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        int left = 0,right = n-1;
        for(int i=n-1;i>=0;i--)
        {
            if(abs(nums[left])>nums[right])
            {
                ans[i] = nums[left]*nums[left];
                left++;
            }
            else
            {
                ans[i] = nums[right]*nums[right];
                right--;
            }
        }
        return ans;
    }
};