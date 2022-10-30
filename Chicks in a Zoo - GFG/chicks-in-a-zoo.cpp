//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    // Code here
	    long arr[n+1];
	    long sum = 1;
	    int idx = 1;
	    arr[1]=1;
	    for(int i=2;i<=n;i++)
	    {
	        if(i>6)
	        {
	            sum-=arr[idx++];
	        }
	        arr[i] = sum*2;
	        sum+=arr[i];
	    }
	    return sum;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends