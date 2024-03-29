class Solution {
public:
    void helper(int idx,vector<int>& candidates,int target,vector<int>& temp,vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<candidates.size();i++)
        {
            if(i > idx && candidates[i]==candidates[i-1])
            {
                continue;
            }
            if(target < candidates[i]) break;
            temp.push_back(candidates[i]);
            helper(i+1,candidates,target-candidates[i],temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0,candidates,target,temp,ans);
        return ans;
    }
};