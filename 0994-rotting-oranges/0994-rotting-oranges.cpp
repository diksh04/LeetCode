class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>>q;//{{i,j},t}
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }
        int time = 0;
        int dRow[4] = {-1,0,1,0};
        int dCol[4] = {0,-1,0,1};
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int t = it.second;
            time = max(time,t);
            for(int i=0;i<4;i++)
            {
                int nRow = r + dRow[i];
                int nCol = c + dCol[i];
                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && !vis[nRow][nCol]
                  && grid[nRow][nCol]==1)
                {
                    q.push({{nRow,nCol},t+1});
                    vis[nRow][nCol] = true;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    return -1;
                }
            }
        }
        return time;
    }
};