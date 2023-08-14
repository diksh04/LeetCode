//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        
        unordered_map<int,int>umap;
        for(auto it:nums)
        {
            umap[it]++;
        }
        vector<int>v;
        for(auto it: umap)
        {
            if(it.second==1)
            {
                v.push_back(it.first);
            }
        }
        if(v[0]>v[1])
        {
            swap(v[0],v[1]);
        }
        return v;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends