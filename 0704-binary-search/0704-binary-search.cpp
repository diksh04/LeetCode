class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0,right = nums.size()-1;
        // -1 0 3 5 9 12
        //  0 1 2 3 4 5
        //  l r m     
        while(left<=right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        return -1;
    }
};