class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        if(strs.size()==0)
        {
            return ans;
        }
        unordered_map<string,vector<string>>map;
        for(auto x:strs)
        {
            string temp = x;
            sort(x.begin(),x.end());
            map[x].push_back(temp);
        }
        for(auto i:map)
        {
            vector<string>res = i.second;
            ans.push_back(res);
        }
        return ans;
    }
};