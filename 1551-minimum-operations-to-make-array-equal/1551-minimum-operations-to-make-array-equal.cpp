class Solution {
public:
    int minOperations(int n) {
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        {
            arr[i] = (2*i)+ 1;
        }
        int ans = 0;
        for(int i=0;i<n/2;i++)
        {
            int diff = arr[n-i-1] - arr[i];
            ans+=(diff/2);
        }
        return ans;
    }
};
// 1 3 5 7 9 11