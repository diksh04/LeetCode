class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        if(nums.size()<3)
        {
            return ans;
        }
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i==0 || nums[i]!=nums[i-1])   
             {
                int lo = i+1;
                int hi = nums.size()-1;
                    while(lo<hi)
                    {
                        int curr = nums[lo]+nums[hi]+nums[i];
                         if(curr==0)
                         {
                             ans.push_back({nums[i],nums[lo],nums[hi]});
                             while(lo<hi && nums[lo]==nums[lo+1])//removal of duplicates
                             {
                                 lo++;
                             }
                             while(lo<hi && nums[hi]==nums[hi-1] )//removal of duplicates
                             {
                                 hi--;
                             }
                             lo++;
                             hi--;
                         }
                        else if(nums[lo]+nums[hi]+nums[i]>0)
                        {
                            hi--;
                        }
                        else
                        {
                            lo++;
                        }
                    }
            }
        }
        return ans;
    }
};
//-4 -1 -1 0 1 2
   // i l  l+1   r

// a+b=0-c;