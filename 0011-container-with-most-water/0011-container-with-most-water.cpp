class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int ans =  INT_MIN;
        
        while(i<=j)
        {
            int breadth = j-i;
            int length = min(height[i],height[j]);
            ans = max(ans,breadth*length);
            if(height[i]>=height[j])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};
// [1,8,6,2,5,4,8,3,7]
//  0 1 2 3 4 5 6 7 8