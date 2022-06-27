class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;
        if(n==1)
        {
            return nums;
        }
        else if(n==2)
        {
            if(nums[1]!=nums[0])
            {
                return nums;
            }
            else
            {
                return {nums[0]};
            }
        }
    
        int c = 1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                c=1;
            }
            else
            {
                c++;
            }
            if(c==n/3+1)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
//  2 3 3