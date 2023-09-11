class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>>umap;
        for(int i=0;i<groupSizes.size();i++)
        {
            umap[groupSizes[i]].push_back(i);
        }
        vector<vector<int>>ans;
        for(auto it:umap)
        {
            int j = 0;
            while(j<it.second.size())
            {
                vector<int>arr;
                for(int i = 0;i<it.first;i++)
                {
                    int x = it.second[j];
                    arr.push_back(x);
                    j++;
                }
                ans.push_back(arr);
            }
        }
        return ans;
    }
};