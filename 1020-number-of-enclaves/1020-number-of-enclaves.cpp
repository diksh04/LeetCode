class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    void dfs(vector<vector<int>>& grid,int x,int y,int &n,int &m)
    {
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]==0)
        {
            return;
        }
        grid[x][y]=0;
        for(int i=0;i<4;i++)
        {
            dfs(grid,x+dx[i],y+dy[i],n,m);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        //boundary-traversal
        int count = 0;
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        // top and bottom wall
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1)
            {
                q.push({0,i});
            }
            if(grid[n-1][i]==1)
            {
                q.push({n-1,i});
            }
        }
        // left and right wall
        for(int i=1;i<n-1;i++)
        {
            if(grid[i][0]==1)
            {
                q.push({i,0});
            }
            if(grid[i][m-1]==1)
            {
                q.push({i,m-1});
            }
        }
        while(!q.empty())
        {
            pair<int,int>front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;
            
            // if(grid[x][y]==0)
            // {
            //     continue;
            // }
            dfs(grid,x,y,n,m);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                count+=grid[i][j];
            }
        }
        return count;
    }
};