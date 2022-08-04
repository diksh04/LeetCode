class Solution {
public:
    static bool compare(pair<int,int>&a,pair<int,int>&b)// a=1->2,b=2->3
    {
        if(a.second==b.second)
        {
            return a.first > b.first;// 3 > 2
        }
        return a.second < b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>umap;
        for(int i=0;i<nums.size();i++)
        {
            umap[nums[i]]++;
        }
        vector<pair<int,int>>res;
        for(auto it:umap)
        {
            res.push_back(it);
        }
        sort(res.begin(),res.end(),compare);
        // 3->1
        // 1
        vector<int>ans;
        for(auto &it:res)
        {
            while(it.second > 0)
            {
                ans.push_back(it.first);
                it.second--;
            }
        }
        return ans;
    }
};
// 1-> 2
// 2-> 3
// 3-> 1
//