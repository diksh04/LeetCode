class Solution {
public:
   int maxSum(vector<vector<int>>& mat) {
    
       int r = mat.size();
       int c = mat[0].size();
       int mxSum = INT_MIN;
       for(int i=0;i<r-2;i++)
       {
           for(int j=0;j<c-2;j++)
           {
               int sum = (mat[i][j] + mat[i][j+1] + mat[i][j+2] + mat[i+1][j+1] + mat[i+2][j] + mat[i+2][j+1] + mat[i+2][j+2]);
               mxSum = max(sum,mxSum);
           }
       }
       return mxSum;
    }
};