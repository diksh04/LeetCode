class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>umap;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            umap[nums[i]]++;
        }
        for(auto it:umap)
        {
            if(it.second>1)
            {
                ans = it.first;
            }
        }
        return ans;
    }
};