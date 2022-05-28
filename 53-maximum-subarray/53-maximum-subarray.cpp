class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // using kadane's algorithm
        int n=nums.size();
        int max_sum=INT_MIN;
        int curr=0;
        for(int i=0;i<n;i++)
        {
           curr+= nums[i];
            if(curr>max_sum)
            {
                max_sum = curr;
            }
            if(curr<0)
            {
                curr=0;
            }
        }
        return max_sum;
    }
};