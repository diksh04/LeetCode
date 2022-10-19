bool comp(pair<string, int>&p1, pair<string, int>& p2){
    if(p1.second==p2.second)
    {
        return p1.first<p2.first;
    }
        
    return p1.second>p2.second;
}
class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>umap;
        for(int i=0;i<words.size();i++)
        {
            umap[words[i]]++;
        }
        vector<pair<string,int>>ans;
        for(auto it: umap)
        {
            ans.push_back(make_pair(it.first,it.second));
        }
        sort(ans.begin(),ans.end(),comp);
        vector<string>res;
        for(int i=0;i<k;i++)
        {
            res.push_back(ans[i].first);
        }
        return res;
    }
};