//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fillingBucket(int N) {
        // code here
        if(N<=2)
        {
            return N;
        }
        int dp[N];
        dp[0] = 1;
        dp[1] = 2;
        for(int i=2;i<N;i++)
        {
            dp[i] = (dp[i-1] + dp[i-2]) % 100000000;
        }
        return dp[N-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends