class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>dp(n,1),hash(n);
        int maxi = 1,lastIdx = 0;
        for(int idx=0;idx<n;idx++)
        {
            hash[idx] = idx;
            for(int prev=0;prev<idx;prev++)
            {
                if(nums[idx]%nums[prev]==0 && dp[idx] < 1 + dp[prev])
                {
                    dp[idx] = 1 + dp[prev];
                    hash[idx] = prev;
                }
            }
            if(maxi < dp[idx])
            {
                maxi = dp[idx];
                lastIdx = idx;
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastIdx]);
        while(hash[lastIdx]!=lastIdx)
        {
            lastIdx = hash[lastIdx];
            ans.push_back(nums[lastIdx]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};