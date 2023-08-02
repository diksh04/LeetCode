class Solution {
public:
    void nextPermu(vector<int>&nums)
    {
        int i = nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1])
        {
            i--;
        }
        if(i>=0)
        {
            int j = nums.size()-1;
            while(j>=0 && nums[j]<=nums[i])
            {
                j--;
            }
            swap(nums[i],nums[j]);
        }
        int st = i+1;
        int end = nums.size()-1;
        while(st<=end)
        {
            int temp = nums[st];
            nums[st]=nums[end];
            nums[end]=temp;
            st++;
            end--;
        }
    }
    int fact(int n)
    {
        if(n==0 || n==1)
        {
            return 1;
        }
        return n*fact(n-1);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int k = fact(n);
        vector<vector<int>>ans;
        ans.push_back(nums);
        for(int i=1;i<k;i++)
        {
            nextPermu(nums);
            ans.push_back(nums); 
        }
        return ans;
    }
};