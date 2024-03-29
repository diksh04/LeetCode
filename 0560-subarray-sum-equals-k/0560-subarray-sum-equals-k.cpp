class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0,count = 0;
        unordered_map<int,int>umap;
        umap[sum] = 1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(umap.find(sum-k)!=umap.end())
            {
                count+=umap[sum-k];
            }
            umap[sum]++;
        }
        return count;
    }
};