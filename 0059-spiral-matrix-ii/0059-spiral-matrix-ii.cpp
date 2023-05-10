class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>arr(n,vector<int>(n));
        int minrow = 0,mincol = 0,maxrow = n-1,maxcol = n-1;
        int elements = n*n;
        int countr = 1;
        while(countr <= elements)
        {
            // top wall
            for(int i = minrow,j = mincol;j<=maxcol && countr <= elements;j++)
            {
                arr[i][j] = countr;
                countr++;
            }
            minrow++;
            //right wall
            for(int i=minrow,j=maxcol;i<=maxrow && countr <= elements;i++)
            {
                arr[i][j] = countr;
                countr++;
            }
            maxcol--;
            //bottom wall
            for(int i=maxrow,j=maxcol;j>=mincol && countr <= elements;j--)
            {
                arr[i][j] = countr;
                countr++;
            }
            maxrow--;
            //left wall
            for(int i=maxrow,j=mincol;i>=minrow && countr <= elements;i--)
            {
                arr[i][j] = countr;
                countr++;
            }
            mincol++;
        }
        return arr;
    }
};