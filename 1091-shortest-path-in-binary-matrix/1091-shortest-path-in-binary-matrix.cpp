class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0){
            return -1;
        }
        if(grid[0][0] == 0 && n==1 & m==1) return 1;
        vector<vector<int>>dist(n,vector<int>(n,1e7));
        dist[0][0] = 0;
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        int dx[8] = {0,1,-1,0,1,-1,1,-1};
        int dy[8] = {1,0,0,-1,1,1,-1,-1};
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int k=0;k<8;k++)
            {
                    int nRow = dx[k] + r;
                    int nCol = dy[k] + c;
                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]==0 && d+1<dist[nRow][nCol])
                    {
                        dist[nRow][nCol] = d + 1;
                        if(nRow==n-1 && nCol==n-1) return d + 1;
                        q.push({d+1,{nRow,nCol}});
                    }
            }
        }
        return -1;
    }
};