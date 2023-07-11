//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int matrix[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		vector<int>ans;
        int elements=n*m;
        int count=0;
        int minrow=0,mincol=0,maxrow=n-1,maxcol=m-1;
    while(count<elements)
    {
        //top wall
        for(int j=mincol,i=minrow;j<=maxcol &&count<elements;j++)
        {
            ans.push_back(matrix[i][j]);
            count++;
        }
        minrow++;
        for(int i=minrow,j=maxcol;i<=maxrow && count<elements;i++)
        {
            ans.push_back(matrix[i][j]);
            count++;
        }
        maxcol--;
        for(int j=maxcol,i=maxrow;j>=mincol && count<elements;j--)
        {
            ans.push_back(matrix[i][j]);
            count++;
        }
        maxrow--;
        for(int i=maxrow,j=mincol;i>=minrow && count<elements;i--)
        {
            ans.push_back(matrix[i][j]);
            count++;
        }
        mincol++;
    }
 		return ans[k-1];
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends