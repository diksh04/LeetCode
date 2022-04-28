class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>arr(n,vector<int>(n));
        int count=1;
        int minrow=0,mincol=0,maxrow=n-1,maxcol=n-1;
        int elements=n*n;
        int countr=1;
    while(countr<=elements)
    {
        for(int j=mincol,i=minrow;j<=maxcol && countr<=elements;j++)//left wall
        {
            arr[i][j]=countr;
            countr++;
        }
        minrow++;
        for(int i=minrow,j=maxcol;i<=maxrow && countr<=elements;i++)//bottom wall
        {
            arr[i][j]=countr;
            countr++;
        }
        maxcol--;
        for(int j=maxcol,i=maxrow;j>=mincol && countr<=elements;j--)//right wall
        {
            arr[i][j]=countr;
            countr++;
        }
        maxrow--;
        for(int i=maxrow,j=mincol;i>=minrow && countr<=elements;i--)//top wall
        {
            arr[i][j]=countr;
            countr++;
        }
        mincol++;
        }
    return arr;
    }
};