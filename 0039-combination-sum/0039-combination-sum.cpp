class Solution {
public:
    void helper(int idx,vector<int>& candidates,int target,vector<int>& temp,vector<vector<int>>& ans)
    {
        if(idx==candidates.size())
        {
            if(target == 0) 
            {
                ans.push_back(temp);
            }
            return;
        }
        if(target >= candidates[idx])
        {
            temp.push_back(candidates[idx]);
            helper(idx,candidates,target-candidates[idx],temp,ans);
            temp.pop_back();
        }
        helper(idx+1,candidates,target,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        helper(0,candidates,target,temp,ans);
        return ans;
    }
};