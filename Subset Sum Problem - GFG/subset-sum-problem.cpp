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
        vector<bool>prev(sum+1,0),curr(sum+1,0);
        prev[0] = curr[0] = true;
        prev[arr[0]] = true;
        for(int idx=1;idx<n;idx++)
        {
            for(int target=1;target<=sum;target++)
            {
                bool notpick = prev[target];
                bool pick = false;
                if(arr[idx]<=target)
                {
                    pick = prev[target-arr[idx]];
                }
                curr[target] = notpick | pick;
            }
            prev = curr;
        }
        return prev[sum];
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