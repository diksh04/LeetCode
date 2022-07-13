class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size()/3;
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++)
        {
            umap[nums[i]]++;
        }
        vector<int>ans;
        for(auto it:umap)
        {
            if(it.second > n)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
//  2 3 3