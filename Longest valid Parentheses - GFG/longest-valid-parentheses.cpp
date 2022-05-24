// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string S){
        // code here
        stack<int>st;
        st.push(-1);
        int MAX = 0;
        for(int i=0;i<S.size();i++)
        {
            char ch = S[i];
            if(ch=='(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.size()==0)
                {
                    st.push(i);
                }
                else
                {
                    MAX = max(MAX,i-st.top());
                }
            }
        }
        return MAX;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends