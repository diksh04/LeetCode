//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int ones = 0,count = 0,mx = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                ones++;
            }
            if(a[i]==0)
            {
                count++;
                if(mx < count)
                {
                    mx = count;
                }
            }
            else if(count!=0)
            { 
                count--;
            }
        }
        if(mx < count)
        {
            mx = count;
        }
        return mx + ones;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends