class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    int start=-1,end=-1;
    int n=nums.size();
    int left=0,right=n-1;
    vector<int>ans;
    while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
            {
                start=mid;
                right=mid-1;
            }
            else if(nums[mid]<target)
            {
                left = mid+1;
            }
            else
            {
                right= mid-1;
            }
        }
        ans.push_back(start);
        left=0,right=n-1;
    while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
            {
                end=mid;
                left=mid+1;
            }
            else if(nums[mid]<target)
            {
                left = mid+1;
            }
            else
            {
                right= mid-1;
            }
        }
        ans.push_back(end);
     return ans;
    }
  
};