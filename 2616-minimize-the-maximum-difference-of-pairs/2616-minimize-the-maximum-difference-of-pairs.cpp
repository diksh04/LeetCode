class Solution {
public:
    bool findPairs(vector<int>& nums,int mid,int p)
    {
        int count = 0;
        // 1 1 2 3 7 10
        // i
        for(int i=0;i<nums.size()-1 && count < p;i++)
        {
            if(nums[i+1]-nums[i] <= mid)
            {
                count++;
                i++;
            }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {//1 2 2 4
        sort(nums.begin(),nums.end());
        int left = 0,right = nums.back()-nums.front();//max diff will be right
        //0 1 2 3 4 5 6 7 8 9
        //l       m         r
        while(left < right)
        {
            int mid = left + (right-left)/2;//4
            if(findPairs(nums,mid,p))
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        return left;
    }
};