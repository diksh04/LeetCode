class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        int val = 0;
        for(int i=0;i<n-2;i++)
        {
            int j = i+1,k = n-1;
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target-sum) < mini)
                {
                    mini =  abs(target-sum);
                    val = sum;
                }
                if(sum > target) k--;
                else j++;
            }
        }
        return val;
    }
};
// -4 -1 1 2
//  0  1 2 3
// target-sum shoudl be minimum