class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long mn = nums[0];
        long long sum = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum+=nums[i];
            if(nums[i]>mn)
            {
                int avg = sum/(i+1);
                if(avg >= mn)
                {
                    if(sum%(i+1))
                    {
                        mn = avg+1;
                    }
                    else
                    {
                        mn = avg;
                    }
                }
            }
        }
        return mn;
    }
};
// 3 10 11 17