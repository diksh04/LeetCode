class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int>check(n+1,false);
        for(int num:nums)
        {
            if(num > 0 && num <= n)
            {
                check[num] = true;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!check[i]) return i;
        }
        return n+1;
    }
};
//3 4 -1 0
//0 1  2 3 