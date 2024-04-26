class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int>umap;
            for(int j=i;j<n;j++)
            {
                umap[s[j]]++;
                int minFreq = INT_MAX,maxFreq = INT_MIN;
                for(auto it:umap)
                {
                    minFreq = min(minFreq,it.second);
                    maxFreq = max(maxFreq,it.second);
                }
                sum+=(maxFreq-minFreq);
            }
        }
        return sum;
    }
};