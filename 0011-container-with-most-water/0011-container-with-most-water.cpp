class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low = 0,high = n-1;
        int area = 0;
        while(low<high)
        {
            int val1 = height[low];
            int val2 = height[high];
            int height = min(val1,val2);
            int width = high-low;
            area = max(area,height*width);
            if(val1>val2)
            {
                high--;
            }
            else{
                low++;
            }
        }
        return area;
    }
};