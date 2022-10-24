//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int>nge(n,0);
        stack<int>st;
        st.push(n-1);
        nge[n-1]=n;
         for(int i=n-2;i>=0;i--)
          {
            while(st.size()>0 && arr[i]>arr[st.top()])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                nge[i]=n;
            }
            else
            {
                nge[i]=st.top();
            }
            st.push(i);
          }
        int j=0;
        vector<int>ans;
        for(int i=0;i<=n-k;i++)
        {
            if(j<i)
            {
                j=i;
            }
            while(nge[j] < i+k)
            {
                j=nge[j];
            }
            ans.push_back(arr[j]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends