class Solution {
public:
     vector<vector<int>>ans;
    void helper(vector<int>& candidates,int idx,int sos,int target,vector<int>res)
    {
        if(idx==candidates.size())
        {
            if(sos==target)
            {
                ans.push_back(res);
            }
            return;
        }
        if(sos>target)
        {
            return;
        }
        if(res.empty() || res.back()!=candidates[idx])
        {
            helper(candidates,idx+1,sos,target,res);
        }
        res.push_back(candidates[idx]);
        helper(candidates,idx+1,sos+candidates[idx],target,res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
       vector<int>res;
        helper(candidates,0,0,target,res);
        return ans;
    }
};