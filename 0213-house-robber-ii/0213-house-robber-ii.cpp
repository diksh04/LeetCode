class Solution {
public:
    int helper(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0,prev=nums[0];
        for(int i=1;i<n;i++)
        {
            int pick = nums[i];
            if(i>1)
            {
                pick+=prev2;
            }
            int notpick = prev + 0;
            int curr = max(pick,notpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0)
            {
                temp1.push_back(nums[i]);
            }
            if(i!=nums.size()-1)
            {
                temp2.push_back(nums[i]);
            }
        }
        int ans1 = helper(temp1);
        int ans2 = helper(temp2);
        return max(ans1,ans2);
    }
};