class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    void dfs(vector<vector<int>>& land,int r,int c,int &row2,int &col2,vector<vector<bool>>& vis)
    {
        vis[r][c] = true;
        row2 = max(r,row2);
        col2 = max(c,col2);
        for(int k=0;k<4;k++)
        {
            int nrow = r + dx[k];
            int ncol = c + dy[k];
            if(nrow>=0 && nrow<land.size() && ncol>=0 && ncol<land[0].size()
              && !vis[nrow][ncol] && land[nrow][ncol]==1)
            {
                dfs(land,nrow,ncol,row2,col2,vis);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        vector<vector<bool>>vis(land.size(),vector<bool>(land[0].size(),false));
        for(int row1 = 0;row1 < land.size(); row1++)
        {
            for(int col1 = 0;col1 < land[0].size(); col1++)
            {
                if(land[row1][col1]==1 && !vis[row1][col1])
                {
                    int row2 = 0,col2 = 0;
                    dfs(land,row1,col1,row2,col2,vis);
                    ans.push_back({row1,col1,row2,col2});
                }
            }
        }
        return ans;
    }
};