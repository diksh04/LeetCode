class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int st = 0,end = n-1;
        int pos = n-1;
        vector<int>ans(n);
        while(st<=end)
        {
            if(abs(nums[st])<abs(nums[end]))
            {
                ans[pos] = nums[end]*nums[end];
                pos--;
                end--;
            }
            else
            {
                ans[pos] = nums[st]*nums[st];
                pos--;
                st++;
            }
        }
        return ans;
    }
};