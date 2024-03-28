class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0,j = 0;
        int cnt = 0;
        unordered_map<int,int>umap;
        while(j<n)
        {
            umap[nums[j]]++;
            while(i<j && umap[nums[j]] > k)
            {
                umap[nums[i]]--;
                i++;
            }
            cnt = max(cnt,j-i+1);
            j++;
        }
        return cnt;
    }
};