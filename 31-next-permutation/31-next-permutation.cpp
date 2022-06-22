class Solution {
public:
    void nextPermutation(vector<int>& nums) {
//         1 1 5 4 1
//         0 1 2 3 5
//         1 4 1 1 5 
        int i = nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1])
        {
            i--;
        }
        if(i>=0)
        {
            int j = nums.size()-1;
            while(j>=0 && nums[j]<=nums[i])
            {
                j--;
            }
            swap(nums[i],nums[j]);
        }
        int st = i+1;
        int end = nums.size()-1;
        while(st<=end)
        {
            int temp = nums[st];
            nums[st]=nums[end];
            nums[end]=temp;
            st++;
            end--;
        }
    }
};