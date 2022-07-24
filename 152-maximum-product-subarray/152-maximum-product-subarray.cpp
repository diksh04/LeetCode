class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pro = 1,mxpro = INT_MIN;
        for(int i=0;i<nums.size();i++)// 6 -3 -10 0 2
        {
            pro = pro * nums[i];
            mxpro = max(mxpro,pro);
            if(pro==0)
            {
                pro=1;
            }
        }
        pro = 1;
        for(int i=nums.size()-1;i>=0;i--) // -8 5 3 1 6
        {
            pro = pro * nums[i];
            mxpro = max(mxpro,pro);
            if(pro==0)
            {
                pro = 1;
            }
        }
        return mxpro;
    }
};