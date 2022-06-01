class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int>ans(n,0);
        for(int i = n-1;i>=0;i--)
        {
            sum = nums[i];
            for(int j = i-1;j>=0;j--)
            {
                sum+=nums[j];
            }
            ans[i]=sum;
        }
        return ans;
    }
};