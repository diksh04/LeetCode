class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>umap;
        for(auto it:s)
        {
            umap[it]++;
        }
        string ans;
        for(auto it:order)
        {
            if(umap.find(it)!=umap.end())
            {
                for(int i=1;i<=umap[it];i++)
                {
                    ans+=it;
                }
                umap.erase(it);
            }
        }
        for(auto it:umap)
        {
            for(int i=1;i<=it.second;i++)
                {
                    ans+=it.first;
                }
        }
        return ans;
    }
};