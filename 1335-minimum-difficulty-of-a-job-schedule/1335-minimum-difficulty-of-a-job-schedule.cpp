class Solution {
public:
    
    int helpme(vector<int>&nums,int d,int idx,int &n,vector<vector<int>>&dp,vector<int>&maxarr)
    {
        if(n<d)
            return -1;
        if(d==1)
            return maxarr[idx];
        if(dp[d][idx]!=-2)
            return  dp[d][idx];
        int ans=INT_MAX;
        int maxTillithIndex=INT_MIN;
        for(int i=idx;i<=n-d;i++)
        {
            maxTillithIndex=max(maxTillithIndex,nums[i]);
            ans=min(ans,maxTillithIndex+helpme(nums,d-1,i+1,n,dp,maxarr));
        }
        return dp[d][idx]=ans;
    }
     int minDifficulty(vector<int>& A, int D) {
       int n=A.size();
         vector<vector<int>>dp(11,vector<int>(301,-2));
         
         //this vector is to store the maxElement in the righwards(i.e. maxarr[i] contains max element from i...n)
         vector<int>maxarr(n,0);
         maxarr[n-1]=A[n-1];
         for(int i=n-2;i>=0;i--)
             maxarr[i]=max(maxarr[i+1],A[i]);
         return helpme(A,D,0,n,dp,maxarr);
    }
};