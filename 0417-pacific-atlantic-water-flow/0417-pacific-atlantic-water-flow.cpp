class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& heights,vector<vector<int>>& vis)
    {
        if(r<0 || r>=heights.size() || c<0 || c>=heights[0].size() || vis[r][c]==1)
        {
            return;
        }
        vis[r][c] = 1;
        if(r-1>=0 && heights[r-1][c] >= heights[r][c])
        {
            dfs(r-1,c,heights,vis);
        }
        if(c-1>=0 && heights[r][c-1] >= heights[r][c])
        {
            dfs(r,c-1,heights,vis);
        }
        if(r+1 < heights.size() && heights[r+1][c] >= heights[r][c])
        {
            dfs(r+1,c,heights,vis);
        }
        if(c+1 < heights[0].size() && heights[r][c+1] >= heights[r][c])
        {
            dfs(r,c+1,heights,vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(),n = heights[0].size();
        vector<vector<int>>pacific(m,vector<int>(n,0));
        vector<vector<int>>atlantic(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            dfs(i,0,heights,pacific);
            dfs(i,n-1,heights,atlantic);
        }
        for(int j=0;j<n;j++)
        {
            dfs(0,j,heights,pacific);
            dfs(m-1,j,heights,atlantic);
        }
        vector<vector<int>>ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
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