class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1]!=nums[i])
            {
                ans+=n-i;
            }
        }
        return ans;
    }
};