class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(),n = mat[0].size();
        int i=0,j=0;
        bool dir = true;
        vector<int>ans;
        ans.push_back(mat[0][0]);
        while(i!=m-1 || j!=n-1)
        {
            if(dir)
            {
                if(j==n-1)
                {
                    i++;
                    dir = false;
                }
                else if(i==0)
                {
                    j++;
                    dir = false;
                }
                else
                {
                    i--;
                    j++;
                }
            }
            else
            {
                if(i==m-1)
                {
                    j++;
                    dir = true;
                }
                else if(j==0)
                {
                    i++;
                    dir = true;
                }
                else
                {
                    i++;
                    j--;
                }
            }
            ans.push_back(mat[i][j]);
        }
        return ans;
    }
};