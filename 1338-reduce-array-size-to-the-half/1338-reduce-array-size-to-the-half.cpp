class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>umap;
        for(int i=0;i<arr.size();i++)
        {
            umap[arr[i]]++;
        }
        vector<int>freq;
        for(auto it:umap)
        {
            freq.push_back(it.second);
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0,n = arr.size(),idx=0;
        while(n>arr.size()/2)
        {
            n-=freq[idx];
            idx++;
            ans++;
        }
        return ans;
    }
};