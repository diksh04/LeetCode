class Solution {
public:
    bool static compare(pair<char,int>& a,pair<char,int>& b)
    {
        return a.second > b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int>umap;
        for(int i=0;i<s.size();i++)
        {
            umap[s[i]]++;
        }
        vector<pair<char,int>>v;
        for(auto x:umap)
        {
            v.push_back({x.first,x.second});
        }
        sort(v.begin(),v.end(),compare);
        string ans;
        for(auto x:v)
        {
            for(int i=0;i<x.second;i++)
            {
                ans+=x.first;
            }
        }
        return ans;
    }
};