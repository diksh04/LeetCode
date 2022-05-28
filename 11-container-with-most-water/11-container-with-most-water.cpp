class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int lo = 0;
        int hi = n-1;
        int area = 0;
        while(lo<hi)
        {
            int val1 = height[lo];
            int val2 = height[hi];
            int minHeight = min(val1,val2);
            int width = hi - lo;
            int ans = minHeight*width;
            area = max(area,ans);
            if(val1>val2)
            {
                hi--;
            }
            else
            {
                lo++;
            }
        }
        return area;
    }
};