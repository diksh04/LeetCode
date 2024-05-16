class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxi = 1,lastIdx = 0;
        vector<int>dp(n,1),hash(n);
        for(int i=0;i<n;i++)
        {
            hash[i] = i; 
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]%nums[prev] == 0 && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(maxi < dp[i])
            {
                maxi = dp[i];
                lastIdx = i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastIdx]);
        while(lastIdx!=hash[lastIdx])
        {
            lastIdx = hash[lastIdx];
            ans.push_back(nums[lastIdx]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};