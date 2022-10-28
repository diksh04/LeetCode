class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        if(strs.size()==0)
        {
            return ans;
        }
        unordered_map<string,vector<string>>umap;
        for(auto x:strs)
        {
            string s = x;
            sort(x.begin(),x.end());
            umap[x].push_back(s);
        }
        for(auto it:umap)
        {
            vector<string>res = it.second;
            ans.push_back(res);
        }
        return ans;
    }
};