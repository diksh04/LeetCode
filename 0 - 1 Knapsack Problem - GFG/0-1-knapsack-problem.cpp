//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int helper(int idx,int maxWeight,int weight[],int value[],vector<vector<int>>& dp)
{
	if(idx==0)
	{
		if(weight[0]<=maxWeight)
		{
			return value[0];
		}
		else
		{
			return 0;
		}
	}
	if(dp[idx][maxWeight]!=-1)
	{
		return dp[idx][maxWeight];
	}
	int notpick = 0 + helper(idx-1,maxWeight,weight,value,dp);
	int pick = INT_MIN;
	if(weight[idx]<=maxWeight)
	{
		pick = value[idx] + helper(idx-1,maxWeight-weight[idx],weight,value,dp);
	}
	return dp[idx][maxWeight] = max(pick,notpick);
}
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return helper(n-1,W,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends