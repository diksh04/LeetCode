class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        //optimized from O(N3) to O(n2)
        vector<int>arr;// 1 3 6 10 2 5 9 
        for(int i=0;i<nums.size();i++)
        {
            int prefixSum = 0;
            for(int j=i;j<nums.size();j++)
            {
                prefixSum+=nums[j];
                arr.push_back(prefixSum);
            }
        }
        sort(arr.begin(),arr.end());
        long long sum = 0;
        for(int i=left;i<=right;i++)
        {
            sum+=arr[i-1];
        }
        return sum%1000000007;
    }
};