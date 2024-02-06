class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char,int>umap;
        for(auto x:s)
        {
            umap[x]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:umap)
        {
            pq.push({it.second,it.first});
        }
        string ans = "";
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            for(int i=0;i<it.first;i++)
            {
                ans+=it.second;
            }
        }
        return ans;
    }
};