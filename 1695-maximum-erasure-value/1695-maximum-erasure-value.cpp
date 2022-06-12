class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>vec(n+1,0);
        for(int i=0;i<n;i++)
        {
            vec[i+1]=vec[i]+nums[i];
        }
        int ans=0,s=0;
        vector<int>res(10001,-1);
        for(int i=0;i<n;i++)
        {
            s = max(s,res[nums[i]]+1);
            ans = max(ans,vec[i+1]-vec[s]);
            res[nums[i]]=i;
        }
        return ans;
    }
};