class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>ans;
        for(int i=0;i<matrix.size();i++)
        {
            int svj = 0;
            for(int j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][svj]>matrix[i][j])
                {
                    svj = j;
                }
            }
            bool flag = true;
            for(int k=0;k<matrix.size();k++)
            {
                if(matrix[k][svj] > matrix[i][svj])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                ans.push_back(matrix[i][svj]);
                // cout<<matrix[i][svj]<<" ";
            }
        }
        return ans;
    }
};
// 3  7  8
// 9  11 13
// 15 16 17