//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis)
    {
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col] = 1;
        int dRow[] = {-1,-1,0,1,1,1,0,-1};
        int dCol[] = {0,1,1,1,0,-1,-1,-1};
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k=0;k<8;k++)
            {
                int nrow = r + dRow[k];
                int ncol = c + dCol[k];
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() &&
                !vis[nrow][ncol] && grid[nrow][ncol]=='1')
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count = 0;
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends