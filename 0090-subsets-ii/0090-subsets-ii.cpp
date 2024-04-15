class Solution {
public:
    void helper(int idx,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans)
    {
        if(idx==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        helper(idx+1,nums,temp,ans);
        temp.pop_back();
        while(idx+1 < nums.size() && nums[idx] == nums[idx+1]) idx++;
        helper(idx+1,nums,temp,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        helper(0,nums,temp,ans);
        return ans;
    }
};