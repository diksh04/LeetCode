class Solution {
public:
    bool helper(vector<vector<int>>& mat,int row,int col)
    {
        int count=0;
        for(int col=0;col<mat[0].size();col++)
        {
            if(mat[row][col] ==1)
            {
                count++;
            }
        }
        if(count>1)
        {
            return false;
        }
        count=0;
        for(int row=0;row<mat.size();row++)
        {
            if(mat[row][col]==1)
            {
                count++;
            }
        }
        if(count>1)
        {
            return false;
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)
                {
                    if(helper(mat,i,j))
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};