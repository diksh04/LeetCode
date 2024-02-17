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
        helper(idx+1,nums,arr,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>arr;
        helper(0,nums,arr,ans);
        return ans;
    }
};