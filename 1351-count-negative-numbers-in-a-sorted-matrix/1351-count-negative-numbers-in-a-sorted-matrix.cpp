class Solution {
public:
    int helper(vector<vector<int>>& grid,int i,int s,int e)
    {
        if(s>e)
        {
            return 0;
        }
        int mid = s + (e-s)/2;
        if(grid[i][mid]<0)
        {
            return (e-mid+1)+helper(grid,i,s,mid-1);
        }
        return helper(grid,i,mid+1,e);
        
    }
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++)
        {
            count+=helper(grid,i,0,grid[0].size()-1);
        }
        return count;
    }
};

// 4 3 2 -1
// 3 2 1 -1
// 1 1 -1 -2
// -1 -1 -2 -3