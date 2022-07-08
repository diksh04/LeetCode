class Solution {
public:
    vector<vector<int>>ans;
    void helper(int n,int k,int idx,vector<int>&res)
    {
        if(res.size()==k)
        {
            ans.push_back(res);
            return;
        }
        for(int i=idx;i<=n;i++)
        {
            res.push_back(i);
            helper(n,k,i+1,res);
            res.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>res;
        helper(n,k,1,res);
        return ans;
    }
};