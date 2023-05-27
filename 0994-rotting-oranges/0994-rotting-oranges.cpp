class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        //{{r,c},time};
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis=grid;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }
        int time = 0;
        int dRow[] = {-1,0,1,0};
        int dCol[] = {0,1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(t,time);
            q.pop();
            for(int j=0;j<4;j++)
            {
                int nrow = r + dRow[j];
                int ncol = c + dCol[j];
                if(nrow >= 0 && nrow < n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1)
                {
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]!=2 && grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return time;
    }
};