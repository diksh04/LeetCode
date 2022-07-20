class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
       int count = 0;
        unordered_map<char,vector<int>>umap;
        for(int i=0;i<s.size();i++)
        {
            umap[s[i]].push_back(i);
        }
        for(int i=0;i<words.size();i++)
        {
            string cur = words[i];
            int latest = -1;
            for(int j=0;j<cur.size();j++)
            {
                auto it = upper_bound(umap[cur[j]].begin(),umap[cur[j]].end(),latest);
                if(it==umap[cur[j]].end())
                {
                    break;
                }
                latest = *it;
                if(j==cur.size()-1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};