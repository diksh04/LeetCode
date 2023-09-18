//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size(),m = image[0].size();
        int initColor = image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int dRow[4] = {-1,0,1,0};
        int dCol[4] = {0,1,0,-1};
        image[sr][sc] = newColor;
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            
            for(int k=0;k<4;k++)
            {
                int nrow = r + dRow[k];
                int ncol = c + dCol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initColor
                && image[nrow][ncol]!=newColor)
                {
                    q.push({nrow,ncol});
                    image[nrow][ncol] = newColor;
                }
            }
        }
    return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends