class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2==1)
        {
            return {};
        }
        
        sort(changed.begin(),changed.end());
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<changed.size();i++)
        {
            mp[changed[i]]++;
        }
        for(int i=0;i<changed.size();i++)
        {
            // 0 1 3 6
            if(mp[changed[i]]==0)
            {
                continue;
            }
            if(mp[changed[i]*2]==0)
            {
                return {};
            }
            ans.push_back(changed[i]);
            mp[changed[i]]--;
            mp[changed[i]*2]--;
        }
        return ans;
    }
};