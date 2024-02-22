class Solution {
public:
    bool isSafe(int r,int c,vector<string>& board,int n)
    {
        //column check
        for(int i=0;i<board.size();i++)
        {
            if(board[i][c]=='Q')
            {
                return false;
            }
        }
        //upper left diagonal
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
    void helper(int row,vector<string>& board,int n,int &cnt)
    {
        if(row == n){
            cnt++;
            return;
        }
        int count = 0;
        for(int col = 0;col<n;col++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col]='Q';
                helper(row+1,board,n,cnt);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }
        int cnt = 0;
        helper(0,board,n,cnt);
        return cnt;
    }
};