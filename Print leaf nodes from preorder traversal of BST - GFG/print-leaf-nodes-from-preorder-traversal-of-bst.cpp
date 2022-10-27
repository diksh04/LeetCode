//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void helper(int arr[],int N,vector<int>& ans)
    {
        stack<int>st;
        for(int i=0,j=1;j<N;i++,j++)
        {
            bool found = false;
            if(arr[i]>arr[j])
            {
                st.push(arr[i]);
            }
            else
            {
                while(!st.empty())
                {
                    if(arr[j]>st.top())
                    {
                        st.pop();
                        found = true;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if(found)
            {
                ans.push_back(arr[i]);
            }
        }
        ans.push_back(arr[N-1]);
    }
    vector<int> leafNodes(int arr[],int N) {
        // code here
        vector<int>ans;
        helper(arr,N,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends