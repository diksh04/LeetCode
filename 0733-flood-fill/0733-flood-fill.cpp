class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>>& image,int color,int initCol)
    {
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc] == color || image[sr][sc]!=initCol)
        {
            return;
        }
        image[sr][sc] = color;
        dfs(sr-1,sc,image,color,initCol);
        dfs(sr,sc-1,image,color,initCol);
        dfs(sr+1,sc,image,color,initCol);
        dfs(sr,sc+1,image,color,initCol);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initCol = image[sr][sc];
        dfs(sr,sc,image,color,initCol);
        return image;
    }
};