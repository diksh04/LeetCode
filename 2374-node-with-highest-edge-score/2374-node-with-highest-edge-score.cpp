class Solution {
public:
    int edgeScore(vector<int>& edges) {
        long int n = edges.size();
        vector<long int> ans(n,0);
        for(long int i = 0 ; i < n; i++)
        {
            ans[edges[i]]+=i;
        }
        long int maxidx = 0;
        long int maxi = 0;
        for(long int j = 0 ; j<n;j++ )
        {
            if(ans[j]>maxi)
            {
                maxi = ans[j];
                maxidx = j;
            }
        }
        return maxidx;
    }
};