class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int ansSum = 0, n = nums.size(), newTarget = target, ansDiff = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++){
            int currSum = nums[i];
            int j = i+1, k = n-1;
            newTarget = target - nums[i];
            while(j<k){
                int twoSum = nums[j] + nums[k];
                int currDiff = abs(newTarget - twoSum);
                if(twoSum == newTarget) return nums[i] + twoSum;
                if(currDiff < ansDiff){
                    ansDiff = currDiff;
                    ansSum = nums[i] + twoSum;
                }
                if(twoSum < newTarget){
                    j++;
                }
                if(twoSum > newTarget){
                    k--;
                }
            }
        }
        
        return ansSum;
    }
};