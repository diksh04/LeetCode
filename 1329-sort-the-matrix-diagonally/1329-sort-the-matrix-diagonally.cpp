class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int x,y,count;
        for(int i=0;i<n;i++)// iterating through colums
        {
            vector<int>val;
            x = 0;
            y = i;
            while(x < m && y < n)
            {
                val.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(val.begin(),val.end());
            x = 0;
            y = i;
            count = 0;
            while(x < m && y < n)
            {
                mat[x][y] = val[count];
                x++;
                y++;
                count++;
            }
        }
        for(int i=1;i<m;i++) //iterating through rows
        {
            x = i;
            y = 0;
            vector<int>val;
            while(x < m && y < n)
            {
                val.push_back(mat[x][y]);
                x++;
                y++;
            }
              sort(val.begin(),val.end());
            x = i;
            y = 0;
            count = 0;
            while(x < m && y < n)
            {
                mat[x][y] = val[count];
                x++;
                y++;
                count++;
            }
        }
        return mat;
    }
};