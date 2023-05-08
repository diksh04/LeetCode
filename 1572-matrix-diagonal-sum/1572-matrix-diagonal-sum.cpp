class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int r = 0,c = 0;
        while(r < mat.size())
        {
            sum+=mat[r][c];
            r++;
            c++;
        }
        r = 0,c = mat[0].size()-1;
        while(r < mat.size())
        {
            if(r!=c)
            {
                sum+=mat[r][c];
            }
            r++;
            c--;
        }
        return sum;
    }
};