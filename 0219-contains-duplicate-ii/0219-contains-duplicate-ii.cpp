class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++)
        {
            umap[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(umap[nums[i]]==1)
            {
                continue;
            }
            for(int j = i+1;j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                {
                    if(abs(i-j)<=k)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};