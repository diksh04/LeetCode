//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int helper(int idx,int N,int price[],vector<vector<int>>& dp)
    {
    	if(idx==0)
    	{
    		return (N*price[0]);
    	}
    	if(dp[idx][N]!=-1)
    	{
    		return dp[idx][N];
    	}
    	int notpick = 0 + helper(idx-1,N,price,dp);
    	int pick = INT_MIN;
    	int rodlength = idx+1;
    	if(rodlength<=N)
    	{
    		pick = price[idx] + helper(idx,N-rodlength,price,dp);
    	}
    	return dp[idx][N] = max(pick,notpick);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
	    return helper(n-1,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends