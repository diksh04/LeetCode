class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //we can't store at -1 we will coordinate shift         
        vector<int>next(n+1,0),curr(n+1,0);
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int prevIdx=idx-1;prevIdx>=-1;prevIdx--)
            {
                int notTake = 0 + next[prevIdx+1];
                int take = 0;
                if(prevIdx==-1 || nums[idx]>nums[prevIdx])
                {
                    take = 1 + next[idx+1];
                }
                curr[prevIdx+1] = max(take,notTake);
            }
            next = curr;
        }
        return next[0];
    }
};