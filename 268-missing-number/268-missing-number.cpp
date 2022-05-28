class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int ans;
        for(int i=0;i<nums.size();i++)
        {
            if(count==nums[i])
            {
                count++;
            }
            else
            {
                ans=count;
                break;
            }
        }
        return ans;
    }
};
