class Solution {
public:
    bool helper(int r,int c,vector<vector<char>>& board,string word,int k)
    {
        if(k==word.size())
        {
            return true;
        }
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]!=word[k] || board[r][c]=='#')
        {
            return false;
        }
        char ch = board[r][c];
        board[r][c] = '#';
        bool op1 = helper(r-1,c,board,word,k+1);
        bool op2 = helper(r,c-1,board,word,k+1);
        bool op3 = helper(r+1,c,board,word,k+1);
        bool op4 = helper(r,c+1,board,word,k+1);
        board[r][c] = ch;
        return op1 || op2 || op3 || op4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    if(helper(i,j,board,word,0)) return true;
                }
            }
        }
        return false;
    }
};