class Solution {
public:
    void helper(vector<vector<int>>& image,int sr,int sc,int initColor,int color)
    {
        if(sr<0 || sc<0 || sr==image.size() || sc==image[0].size() || image[sr][sc]!=initColor || image[sr][sc] == color)
        {
            return;
        }
        image[sr][sc] = color;
        helper(image,sr-1,sc,initColor,color);
        helper(image,sr,sc-1,initColor,color);
        helper(image,sr+1,sc,initColor,color);
        helper(image,sr,sc+1,initColor,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int initColor = image[sr][sc];
        helper(image,sr,sc,initColor,color);
        return image;
    }
};