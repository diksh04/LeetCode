class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool>prev(k+1,0),curr(k+1,0);
    prev[0] = curr[0] = true;
    if(arr[0]<=k) prev[arr[0]] = true;
    for(int i=1;i<n;i++)
    {
        for(int tar=1;tar<=k;tar++)
        {
            bool notpick = prev[tar];
            bool pick = false;
            if(arr[i]<=tar)
            {
                pick = prev[tar-arr[i]];
            }
            curr[tar] = pick | notpick;
        }
        prev = curr;
    }
    return prev[k];
}
    bool canPartition(vector<int>& nums) {
        int tsum = accumulate(nums.begin(),nums.end(),0);
        if(tsum%2) return false;
        int sum = tsum/2;
       int n = nums.size();
        return subsetSumToK(n,sum,nums);
    }
};