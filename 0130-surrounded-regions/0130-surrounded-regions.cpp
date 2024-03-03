class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>& vis)
    {
        vis[i][j] = true;
        for(int idx=0;idx<4;idx++)
        {
            int nRow = i + dx[idx];
            int nCol = j + dy[idx];
            if(nRow>=0 && nRow<board.size() && nCol>=0 && nCol<board[0].size()
              && !vis[nRow][nCol] && board[nRow][nCol]=='O')
            {
                dfs(nRow,nCol,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            if(!vis[i][0] && board[i][0]=='O')
            {
                dfs(i,0,board,vis);
            }
            if(!vis[i][n-1] && board[i][n-1]=='O')
            {
                dfs(i,n-1,board,vis);
            }
        }
        for(int j=0;j<n;j++)
        {
            if(!vis[0][j] && board[0][j]=='O')
            {
                dfs(0,j,board,vis);
            }
            if(!vis[m-1][j] && board[m-1][j]=='O')
            {
                dfs(m-1,j,board,vis);
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && board[i][j]=='O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};