class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int>umap;
        int count = 0,left = 0;
        for(int i=0;i<nums.size();i++)
        {
            umap[nums[i]]++;
        }
        for(auto x:umap)
        {
            left+=x.second%2;
            count+=x.second/2;
        }
        return {count,left};
    }
};
// 1->2  --> count = 2/2 = 1 && left = 2%2=0
// 2->3
// 3->2
