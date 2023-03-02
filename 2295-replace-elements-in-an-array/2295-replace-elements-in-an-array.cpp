class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++)
        {
            umap[nums[i]] = i;
        }
        for(int i=0;i<operations.size();i++)
        {
            nums[umap[operations[i][0]]] = operations[i][1];
            umap[operations[i][1]] = umap[operations[i][0]];
        }
        return nums;
    }
};