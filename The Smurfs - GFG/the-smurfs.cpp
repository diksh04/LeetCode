//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        int redCount = 0,blueCount = 0,greenCount = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i] == 'R')
            {
                redCount++;
            }
            else if(a[i]=='B')
            {
                blueCount++;
            }   
            else
            {
                greenCount++;
            }
        }
        if(redCount == n || blueCount == n || greenCount == n)
        {
            return n;
        }
        if((greenCount%2==0) && (redCount%2==0) && (blueCount%2==0) || 
        (greenCount%2==1) && (redCount%2==1) && (blueCount%2==1))
        {
            return 2;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends