class Solution {
public:
    int getSum(int num)
    {
        int s = 0;
        while(num!=0)
        {
            int rem = num%10;
            s+=rem;
            num/=10;
        }
        return s;
    }
    int maximumSum(vector<int>& nums) {
        
        unordered_map<int,vector<int>>umap;
        for(int i=0;i<nums.size();i++)
        {
            int sum = getSum(nums[i]);
            // cout<<sum<<endl;
            umap[sum].push_back(nums[i]);
        }
        int mx = -1;
        for (auto x: umap) {
            
            if (x.second.size() > 1) {
                vector<int>ans= x.second; 
                sort(ans.rbegin(), ans.rend());
                mx= max(mx, ans[0]+ ans[1]); 
            }
        }
        return mx;
    }
};
// 9--> 18,36
// 7--> 43,7