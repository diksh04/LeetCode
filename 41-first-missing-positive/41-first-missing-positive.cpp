class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int n = nums.size();
        for(int i=0;i<n;i++)// 1 2 0
        {
            int temp = nums[i];//
            
            if(temp>=1 && temp<=n)
            {
                int position = temp-1;//correct position
                if(nums[position]!=temp)
                {
                    swap(nums[position],nums[i]);
                    i--;
                }
            } 
        }
        for(int i=0;i<n;i++)
        {
            if(i+1!=nums[i])
            {
                return i+1;
            }
        }
        return n+1;
    }
};