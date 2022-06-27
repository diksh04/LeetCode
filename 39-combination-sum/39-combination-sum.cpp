class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>& candidates,int idx,int sos,int target,vector<int>res)
    {
            if(sos==target)
            {
                ans.push_back(res);
                return;
            } 
        for(int i=idx;i<candidates.size();i++)
        {
            if(sos+candidates[i]<=target)
            {
                res.push_back(candidates[i]);
                helper(candidates,i,sos+candidates[i],target,res);
                res.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>res;
        helper(candidates,0,0,target,res);
        return ans;
    }
};