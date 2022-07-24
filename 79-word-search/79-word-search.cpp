class Solution {
public:
    bool helper(vector<vector<char>>&board,string &word,int pos,int i,int j)
    {
        if(pos==word.size())
        {
            return true;
        }
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0 || board[i][j]=='#')
        {
            return false;
        }
        if(word[pos]!=board[i][j])
        {
            return false;
        }
        char temp = board[i][j];
        board[i][j]='#';
        if(helper(board,word,pos+1,i-1,j))
        {
            return true;
        }
        if(helper(board,word,pos+1,i,j+1))
        {
            return true;
        }
        if(helper(board,word,pos+1,i+1,j))
        {
            return true;
        }
        if(helper(board,word,pos+1,i,j-1))
        {
            return true;
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(helper(board,word,0,i,j))
                  {
                       return true;
                  }
            }
        }
        
    return false;
           
    }
};