//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char,int>umap;
        umap.insert(make_pair('I',1));
        umap.insert(make_pair('V',5));
        umap.insert(make_pair('X',10));
        umap.insert(make_pair('L',50));
        umap.insert(make_pair('C',100));
        umap.insert(make_pair('D',500));
        umap.insert(make_pair('M',1000));
        int ans = 0;
        for(int i=0;i<str.size();)
        {
            if(i==str.size()-1 || umap[str[i]] >= umap[str[i+1]])
            {
                ans+=umap[str[i]];
                i++;
            }
            else
            {
                ans+=umap[str[i+1]] - umap[str[i]];
                i+=2;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends