//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool helper(int idx,int sum,vector<int>& arr,vector<vector<int>>& dp)
    {
        if(sum==0)
        {
            return true;
        }
        if(idx==0)
        {
            return arr[0] == sum;
        }
        if(dp[idx][sum]!=-1)
        {
            return dp[idx][sum];
        }
        bool notpick = helper(idx-1,sum,arr,dp);
        bool pick = false;
        if(arr[idx]<=sum)
        {
            pick = helper(idx-1,sum-arr[idx],arr,dp);
        }
        return dp[idx][sum] = notpick | pick;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
        for(int i=0;i<n;i++)
        {
            dp[i][0] = true;
        }
        dp[0][arr[0]] = true;
        for(int idx=1;idx<n;idx++)
        {
            for(int target=1;target<=sum;target++)
            {
                bool notpick = dp[idx-1][target];
                bool pick = false;
                if(arr[idx]<=target)
                {
                    pick = dp[idx-1][target-arr[idx]];
                }
                dp[idx][target] = notpick | pick;
            }
        }
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends