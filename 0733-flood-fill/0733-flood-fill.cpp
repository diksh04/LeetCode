class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initColor = image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc] = color;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            int dRow[4] = {-1,0,1,0};
            int dCol[4] = {0,-1,0,1};
            for(int i=0;i<4;i++)
            {
                int nRow = r + dRow[i];
                int nCol = c + dCol[i];
                if(nRow>=0 && nRow<image.size() && nCol>=0 && nCol<image[0].size() && image[nRow][nCol]==initColor && image[nRow][nCol]!=color)
                {
                    q.push({nRow,nCol});
                    image[nRow][nCol] = color;
                }
            }
        }
        return image;
    }
};