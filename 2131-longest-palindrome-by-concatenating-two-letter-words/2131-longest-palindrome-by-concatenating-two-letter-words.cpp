class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int len = 0;
        unordered_map<string,int>umap;
        for(string &s:words)
        {
            reverse(s.begin(),s.end());
            if(umap.find(s)!=umap.end())
            {
                len+=4;
                umap[s]--;
                if(umap[s]==0)
                {
                    umap.erase(s);
                }
            }
            else
            {
                reverse(s.begin(),s.end());
                umap[s]++;
            }
        }
        for(auto it:umap)
        {
            if(it.first[0] == it.first[1])
            {
                len+=2;
                return len;
            }
        }
        return len;
    }
};