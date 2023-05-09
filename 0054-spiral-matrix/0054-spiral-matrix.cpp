class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        int elements=n*m;
        int count=0;
        int minrow=0,mincol=0,maxrow=n-1,maxcol=m-1;
    while(count<elements)
    {
        //top wall
        for(int j=mincol,i=minrow;j<=maxcol &&count<elements;j++)
        {
            ans.push_back(matrix[i][j]);
            count++;
        }
        minrow++;
        for(int i=minrow,j=maxcol;i<=maxrow && count<elements;i++)
        {
            ans.push_back(matrix[i][j]);
            count++;
        }
        maxcol--;
        for(int j=maxcol,i=maxrow;j>=mincol && count<elements;j--)
        {
            ans.push_back(matrix[i][j]);
            count++;
        }
        maxrow--;
        for(int i=maxrow,j=mincol;i>=minrow && count<elements;i--)
        {
            ans.push_back(matrix[i][j]);
            count++;
        }
        mincol++;
    }
        return ans;
    }
};