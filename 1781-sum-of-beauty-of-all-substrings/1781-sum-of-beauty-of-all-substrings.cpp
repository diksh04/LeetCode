class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int>umap;
            for(int j=i;j<n;j++)
            {
                umap[s[j]]++;
                int maxFreq = INT_MIN,minFreq = INT_MAX;
                for(auto it:umap)
                {
                    maxFreq = max(maxFreq,it.second);
                    minFreq = min(minFreq,it.second);
                }
                sum+=(maxFreq-minFreq);
            }
        }
        return sum;
    }
};