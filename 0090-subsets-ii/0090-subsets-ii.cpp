class Solution {
public:
    void helper(int idx,vector<int>& nums,vector<int>& arr,vector<vector<int>>& ans)
    {
        if(idx==nums.size())
        {
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[idx]);
        helper(idx+1,nums,arr,ans);
        arr.pop_back();
        while(idx+1 < nums.size() && nums[idx]==nums[idx+1]) idx++;
        helper(idx+1,nums,arr,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>arr;
        sort(nums.begin(),nums.end());
        helper(0,nums,arr,ans);
        return ans;
    }
};