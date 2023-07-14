class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int,int>umap;
        int len = 1;
        for(auto x:arr)
        {
            if(umap.count(x-difference))
            {
                umap[x] = umap[x-difference]+1;
            }
            else
            {
                umap[x]=1;
            }
            len = max(len,umap[x]);
        }
        return len;
    }
};