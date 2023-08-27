//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1000000007;
	int helper(int idx,int k,int arr[],vector<vector<int>>& dp)
    {
    	if(idx==0){
            if(arr[0]==0 && k==0)return 2;
            if(k==0 || arr[0]==k)return 1;
            return 0;
        }
    	if(dp[idx][k]!=-1)
    	{
    		return dp[idx][k];
    	}
    	int notpick = helper(idx-1, k, arr, dp)%mod;
    	int pick = 0;
    	if(arr[idx]<=k)
    	{
    		pick = helper(idx-1, k-arr[idx], arr, dp)%mod;
    	}
    	return dp[idx][k] = ((notpick)%mod+(pick)%mod)%mod;
    }
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
    	vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    	return helper(n-1,sum,arr,dp)%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends