class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k==nums.size())
           {
                return nums;   
           }
        vector<int>ans;
        unordered_map<int,int>umap;
        // priorty_queue<pair<int,int>>pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++)
        {
            umap[nums[i]]++;
        }
        for(auto x: umap)
        {
            pq.push({x.second,x.first});
        }
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
    
        return ans;
    }
};