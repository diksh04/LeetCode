class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool>umap;
        for(int i=0;i<nums.size();i++)
        {
            umap[nums[i]]=true;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(umap.find(nums[i]-1)!=umap.end())
            {
                umap[nums[i]]=false;
            }
        }
        int len = 0;
        for(int val:nums)
        {
            if(umap[val]==true)
            {
                int tsp = val;
                int tlen = 1;//temporary len
                while(umap.find(tsp+tlen)!=umap.end())
                {
                    tlen++;
                }
                if(tlen>len)
                {
                    len = tlen;
                }
            }
        }
        return len;
    }
};