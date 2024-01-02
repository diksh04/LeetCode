class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size(),noRows = 0;
        vector<int>freq(n+1,0);
        for(auto x:nums)
        {
            freq[x]++;
        }
        for(int x:freq)
        {
            noRows = max(noRows,x);
        }
        vector<vector<int>>ans(noRows);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<freq[i];j++)
            {
                ans[j].push_back(i);
            }
        }
        return ans;
    }
};