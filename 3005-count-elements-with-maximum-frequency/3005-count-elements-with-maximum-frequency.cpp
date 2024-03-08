class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>umap;
        int maxFreq = 0;
        for(auto it:nums)
        {
            umap[it]++;
            maxFreq = max(maxFreq,umap[it]);
        }
        int cnt = 0;
        for(auto it:umap){
            if(it.second==maxFreq){
                cnt+=it.second;
            }
        }
        return cnt;
    }
};