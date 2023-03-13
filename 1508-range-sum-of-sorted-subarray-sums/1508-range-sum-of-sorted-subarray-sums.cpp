class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long int>ans;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                long long int sum = 0;
                for(int k=i;k<=j;k++)
                {
                    sum+=nums[k];
                }
                ans.push_back(sum);
            }
        }
        sort(ans.begin(),ans.end());
        long long int res=0;
        for(int i=left;i<=right;i++)
        {
            res+=ans[i-1];
        }
        return res%1000000007;
    }
};