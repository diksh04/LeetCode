class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if(nums[0]==0) return true;
        int n = nums.size();
        int reach = 0;
        for(int i=0;i<n;i++)
        {
            if(i>reach) 
            {
                return false;
            }
            reach = max(reach,i+nums[i]);
        }
        return true;
    }
};