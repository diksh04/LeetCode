class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int low = 0,high = n-1;
        int leftMax = INT_MIN,rightMax = INT_MIN;
        int ans = 0;
        while(low<=high)
        {
            if(height[low]<=height[high])
            {
                if(height[low]>=leftMax)
                {
                    leftMax = height[low];
                }
                else
                {
                    ans+=(leftMax-height[low]);
                }
                low++;
            }
            else
            {
                if(height[high]>=rightMax) rightMax = height[high];
                else ans+=(rightMax-height[high]);
                high--;
            }
        }
        return ans;
    }
};