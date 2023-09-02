class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1),hash(n);
        int maxi = 1;
        int lastIdx = 0;
        for(int idx=0;idx<n;idx++)
        {
            hash[idx] = idx;
            for(int prev=0;prev<idx;prev++)
            {
                if(nums[idx]%nums[prev] == 0 && 1+dp[prev] > dp[idx])
                {
                    dp[idx] = 1+dp[prev];
                    hash[idx] = prev;
                }
            }
            if(dp[idx]>maxi)
            {
                maxi = dp[idx];
                lastIdx = idx;
            }
        }
        vector<int>temp;
        temp.push_back(nums[lastIdx]);
        while(hash[lastIdx]!=lastIdx)
        {
            lastIdx = hash[lastIdx];
            temp.push_back(nums[lastIdx]); 
        }
        reverse(temp.begin(),temp.end());
        return temp;
        
    }
};