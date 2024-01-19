class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
    int m = matrix[0].size();
    vector<int>prev(m,0),curr(m,0);
    for(int j=0;j<m;j++)
    {
        prev[j] = matrix[0][j];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int up = matrix[i][j] + prev[j];
            int leftd=matrix[i][j],rightd=matrix[i][j];
            if (j - 1 >= 0) {
              leftd+= prev[j - 1];
            }
            else{
                leftd+= 1e9;
            }
            if(j + 1 < m)
            {
                rightd+= prev[j+1];
            }
            else
            {
                rightd+=1e9;
            }
            curr[j] = min(up,min(leftd,rightd));
        }
        prev = curr;
    }
    int mini = 1e9;
    for(int j=0;j<m;j++)
    {
        mini = min(mini,prev[j]);
    }
    return mini;
    }
};