class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& image,int initColor,int color)
    {
        if(r<0 || r>=image.size() || c<0 || c>=image[0].size() || image[r][c]==color || image[r][c]!=initColor)
        {
            return;
        }
        image[r][c] = color;
        dfs(r-1,c,image,initColor,color);
        dfs(r,c-1,image,initColor,color);
        dfs(r+1,c,image,initColor,color);
        dfs(r,c+1,image,initColor,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initColor = image[sr][sc];
        dfs(sr,sc,image,initColor,color);
        return image;
    }
};