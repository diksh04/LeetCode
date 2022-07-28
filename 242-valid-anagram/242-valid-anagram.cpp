class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>umap;
        int i = 0;
        // int j = 0;
        while(i<s.size() || i<t.size())
        {
            umap[s[i]]++;
            umap[t[i]]--;
            i++;
        }
        for(auto it:umap)
        {
            if(it.second >=1)
            {
                return false;
            }
        }
        return true;
    }
};