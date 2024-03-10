class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& heights,vector<vector<int>>& vis)
    {
        if(i<0 || i>=heights.size() || j<0 || j>= heights[0].size() || vis[i][j]==1)
        {
            return;
        }
        vis[i][j] = 1;
        if(i-1>=0 && heights[i-1][j]>=heights[i][j])
        {
            dfs(i-1,j,heights,vis);
        }
        if(j-1>=0 && heights[i][j-1]>= heights[i][j])
        {
            dfs(i,j-1,heights,vis);
        }
        if(i+1<heights.size() && heights[i+1][j]>=heights[i][j])
        {
            dfs(i+1,j,heights,vis);
        }
        if(j+1<heights[0].size() && heights[i][j+1]>=heights[i][j])
        {
            dfs(i,j+1,heights,vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            dfs(i,0,heights,pacific);
            dfs(i,m-1,heights,atlantic);
        }
        for(int j=0;j<m;j++)
        {
            dfs(0,j,heights,pacific);
            dfs(n-1,j,heights,atlantic);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j]==1 && atlantic[i][j]==1)
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};