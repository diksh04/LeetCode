class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // [1,1,2,3,3,4,4,8,8]
        // l        m       r 
        // [0,1,2,3,4,5,6,7,8,9]
        if(nums.size()==1)
        {
            return nums[0];
        }
        int left = 0,right = nums.size()-1;
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            if(mid%2==0)
            {
                if(nums[mid]==nums[mid+1])
                {
                    left = mid+1;
                }
                else
                {
                    right = mid-1;
                }
            }
            else
            {
              if(nums[mid]==nums[mid-1])  
              {
                  left = mid+1;
              }
              else
              {
                  right = mid-1;
              }
            }
        }
        return nums[left];
    }
};