class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>umap;
        int sum = 0;
        int i = 0;
        int cnt = 0;
        while(i<nums.size())
        {
            sum+=nums[i];
            if(sum==goal) cnt++;
            if(umap.find(sum-goal)!=umap.end())
            {
                cnt+=umap[sum-goal];
            }
            umap[sum]++;
            i++;
        }
        return cnt;
    }
};
// 1 -> 2,2->2
// 1 0 1 0 1  sum=2,cnt = 2
//         i  