class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            mx = max(mx,nums[i]);
            mn = min(mn,nums[i]);
        }
        int rem = 1;
        while(rem!=0)
        {
            rem=mx%mn;
            if(rem!=0)
            {
                mx=mn;
                mn=rem;
            }  
        }
        return mn;
    }
};