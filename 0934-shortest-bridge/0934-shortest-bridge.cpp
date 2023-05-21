class Solution {
public:
    void dfs(int i,int j,queue<pair<int,int>>& q,vector<vector<int>>& grid,int n)
    {
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j]==-1)
        {
            return;
        }
        if(grid[i][j]==0)
        {
            return;
        }
        q.push({i,j});
        grid[i][j]=-1;
        dfs(i-1,j,q,grid,n);
        dfs(i+1,j,q,grid,n);
        dfs(i,j-1,q,grid,n);
        dfs(i,j+1,q,grid,n);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int ans = 0;
        int n = grid.size();
        bool check = true;
        for(int i=0;i<n;i++)
        {
            if(check)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]==1)
                    {
                        dfs(i,j,q,grid,n);
                        check=false;
                        break;
                    }
                }
            }
        }
        while(!q.empty())
        {
            int len = q.size();
            ans++;
            int row[] = {0,0,-1,1};
            int col[] = {-1,1,0,0};
            for(int i=0;i<len;i++)
            {
                auto it = q.front();
                q.pop();
                int cr = it.first;
                int cc = it.second;
                for(int j=0;j<4;j++)
                {
                    int nr = cr + row[j];
                    int nc = cc + col[j];
                    if(nr>=0 && nc>=0 && nr<n && nc<n)
                    {
                        if(grid[nr][nc]==0)
                        {
                            q.push({nr,nc});
                            grid[nr][nc]=-1;
                        }
                        else
                        {
                            if(grid[nr][nc]==1)
                            {
                                return ans-1;
                            }
                        }
                    }
                }
            }
        }
        return ans-1;
    }
};
// 1 1 1 1 1 
// 1 0 0 0 1
// 1 0 1 0 1
// 1 0 0 0 1
// 1 1 1 1 1