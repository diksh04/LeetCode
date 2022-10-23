class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>res;
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++)
        {
            if(umap.find(nums[i])!=umap.end())
            {
                res.push_back(nums[i]);
            }
            umap[nums[i]]++;
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(umap.find(i)==umap.end())
            {
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};