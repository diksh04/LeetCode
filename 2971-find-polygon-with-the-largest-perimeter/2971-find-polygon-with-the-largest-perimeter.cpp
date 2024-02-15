class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //1 12 1 -> 1+1 < 12(fails that is why we sort the array)
        // [1,1,2,3,5,12,50]
        long long ans = -1,sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(sum > nums[i])
            {
                ans = sum + nums[i];
            }
            sum+=nums[i];
        }
        return ans;
    }
};