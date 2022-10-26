class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int curr_sum = 0;
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++)
        {
            curr_sum+=nums[i];
            curr_sum%=k;
            if(curr_sum == 0 && i>0)
            {
                return true;
            }
            else if(umap.find(curr_sum)!=umap.end())
            {
                if(i-umap[curr_sum]>1)
                {
                    return true;
                }
            }
            else
            {
                umap[curr_sum] = i;
            }
            // 5 -> 0,1->1,
        }
        return false;
    }
};