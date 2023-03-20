class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
//         1 2 3 5 6
//         i
//         j
        sort(nums.begin(),nums.end());
        int count=0,j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]-nums[j]>k)
            {
                count++;
                j=i;
            }
        }
        return count+1;
    }
};