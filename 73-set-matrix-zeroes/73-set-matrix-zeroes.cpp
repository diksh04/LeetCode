class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row = matrix.size(),col = matrix[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)// 0,0,0,
            {
                if(matrix[i][j]==0)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        for(int i=0;i<ans.size();i+=2)//for manupulating row's to 0
        {
            for(int j=0;j<col;j++)
            {
                matrix[ans[i]][j]=0;
            }
        }
        for(int j=1;j<ans.size();j+=2)
        {
            for(int i=0;i<row;i++)
            {
                matrix[i][ans[j]]=0;
            }
        }
    }
};