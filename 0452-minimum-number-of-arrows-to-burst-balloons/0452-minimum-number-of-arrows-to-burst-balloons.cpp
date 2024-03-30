class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());
        int end = points[0][1];
        int arrows = 1;
        for(int i=1;i<n;i++)
        {
            if(points[i][0] > end)
            {
                arrows++;
                end = points[i][1];
            }
            else
            {
                end = min(end,points[i][1]);
            }
        }
        return arrows;
    }
};
// [1,6] [2,8] [7,12] [10,16]