//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool helper(int idx,int row,int col,int d1,int d2,vector<vector<char>>grid,string word)
    {
        if(idx==word.size())
        {
            return true;
        }
        int nrow = row + d1;
        int ncol = col + d2;
        if(nrow >=0 && ncol >=0 && nrow<grid.size() && ncol<grid[0].size())
        {
            if(grid[nrow][ncol]==word[idx])
            {
                if(helper(idx+1,nrow,ncol,d1,d2,grid,word))
                {
                    return true;
                }
            }
        }
        return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    set<vector<int>>s;
	    int dx[] = {1,0,-1,0,1,1,-1,-1};
	    int dy[] = {0,1,0,-1,-1,1,1,-1};
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(word[0]==grid[i][j])
	            {
	                for(int k=0;k<8;k++)
	                {
	                    if(helper(1,i,j,dx[k],dy[k],grid,word))
	                    {
	                        s.insert({i,j});
	                    }
	                }
	            }
	        }
	    }
	    vector<vector<int>>ans(s.begin(),s.end());
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends