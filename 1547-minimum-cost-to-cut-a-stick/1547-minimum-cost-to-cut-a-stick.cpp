class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();//initial cuts array size
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        for(int i=c;i>=1;i--)
        {
            for(int j=1;j<=c;j++)
            {
                if(i>j)
                {
                    continue;
                }
                int mini = INT_MAX;
                for(int idx=i;idx<=j;idx++)
                {
                    int cost = cuts[j+1]-cuts[i-1] + dp[i][idx-1] +dp[idx+1][j];
                    mini = min(mini,cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};