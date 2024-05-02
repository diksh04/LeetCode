class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        set<int>st;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
            if(st.find(-1*nums[i])!=st.end())
            {
                ans = max(ans,abs(nums[i]));
            }
        }
        return ans;
    }
};