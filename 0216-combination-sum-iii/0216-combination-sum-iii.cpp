class Solution {
public:
    void helper(int idx,int target,int k,vector<int>& temp,vector<vector<int>>& ans)
    {
        if(target<0 || temp.size()>k)
        {
            return;
        }
        if(target==0 && temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<=9;i++)
        {
            temp.push_back(i);
            helper(i+1,target-i,k,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(1,n,k,temp,ans);
        return ans;
    }
};