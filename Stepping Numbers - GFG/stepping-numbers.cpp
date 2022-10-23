//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void dfs(int num,int n,int m,int &count)
    {
        if(num > m)
        {
            return;
        }
        int lastDigit = num%10;
        if(num>=n && num<=m)
        {
            count++;
        }
        if(lastDigit!=0)
        {
            dfs(10*num+(lastDigit-1),n,m,count);
        }
        if(lastDigit!=9)
        {
            dfs(10*num+(lastDigit+1),n,m,count);
        }
    }
    int steppingNumbers(int n, int m)
    {
        // Code Here
        int count=0;
        if(n==0)
        {
            count++;
        }
        for(int i=1;i<=9;i++)
        {
            dfs(i,n,m,count);
        }
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends