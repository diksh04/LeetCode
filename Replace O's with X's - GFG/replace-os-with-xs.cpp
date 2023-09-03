//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dRow[4]={-1,0,1,0};
    int dCol[4]={0,1,0,-1};
    void dfs(int r,int c,vector<vector<char>>& mat,vector<vector<int>>& vis)
    {
        vis[r][c] = 1;
        for(int j=0;j<4;j++)
        {
            int nrow = r + dRow[j];
            int ncol = c + dCol[j];
            if(nrow>=0 && nrow<mat.size() && ncol>=0 && ncol<mat[0].size() && !vis[nrow][ncol] && mat[nrow][ncol]=='O')
            {
                dfs(nrow,ncol,mat,vis);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        //top row and bottom row
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && mat[0][j]=='O')
            {
                dfs(0,j,mat,vis);
            }
            if(!vis[n-1][j] && mat[n-1][j]=='O')
            {
                dfs(n-1,j,mat,vis);
            }
        }
        // first and last col
        for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && mat[i][0]=='O')
            {
                dfs(i,0,mat,vis);
            }
            if(!vis[i][m-1] && mat[i][m-1]=='O')
            {
                dfs(i,m-1,mat,vis);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && mat[i][j]=='O')
                {
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends