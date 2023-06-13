class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        for(int r = 0;r < n;r++)
        {
            for(int c = 0; c < n ;c++)
            {
                bool check = true;
                for(int i=0;i<n;i++)
                {
                    if(grid[r][i]!=grid[i][c])
                    {
                        check = false;
                        break;
                    }
                }
                if(check)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

// 3 2 1 -> 1
// 1 7 6 -> 1
// 2 7 7 -> 1
// 