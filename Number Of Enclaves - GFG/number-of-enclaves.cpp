//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<int>>& grid)
    {
        vis[r][c] = true;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        for(int k=0;k<4;k++)
        {
            int nrow = r + dx[k];
            int ncol = c + dy[k];
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
                dfs(nrow,ncol,vis,grid);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && grid[0][j]==1)
            {
                dfs(0,j,vis,grid);
            }
            if(!vis[n-1][j] && grid[n-1][j]==1)
            {
                dfs(n-1,j,vis,grid);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && grid[i][0]==1)
            {
                dfs(i,0,vis,grid);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1)
            {
                dfs(i,m-1,vis,grid);
            }
        }
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends