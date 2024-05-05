class Solution {
public:
    bool isSafe(int r,int c,vector<string>& board,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(board[i][c] == 'Q')
            {
                return false;
            }
        }
        int row = r,col = c;
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        row = r,col = c;
        while(row>=0 && col<n)
        {
            if(board[row][col]=='Q') return false;
            row--;
            col++;
        }
        return true;
    }
    void helper(int row,vector<string>& board,vector<vector<string>>& ans,int n)
    {
        if(row == n)
        {
            ans.push_back(board);
            return;
        }
        for(int col = 0;col < n;col++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col] = 'Q';
                helper(row+1,board,ans,n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }
        helper(0,board,ans,n);
        return ans;
    }
};