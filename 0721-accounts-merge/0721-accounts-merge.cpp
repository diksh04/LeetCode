class DisjointSet {
	   vector<int>rank,parent;
	   public:
	    DisjointSet(int n){
	        rank.resize(n+1,0);
	        parent.resize(n+1);
	        for(int i=0;i<=n;i++)
	        {
	            parent[i] = i;
	        }
	    }
	    int findParent(int node){
	        if(node == parent[node]) return node;
	        return parent[node] = findParent(parent[node]);
	    }
	    void unionByRank(int u,int v){
	        int ultiU = findParent(u);
	        int ultiV = findParent(v);
	        if(ultiU == ultiV) return;
	        if(rank[ultiU] > rank[ultiV])
	        {
	            parent[ultiV] = ultiU;
	        }
	        else if(rank[ultiV] > rank[ultiU])
	        {
	            parent[ultiU] = ultiV;
	        }
	        else
	        {
	            parent[ultiV] = ultiU;
	            rank[ultiU]++;
	        }
	    }
	};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>umap;//mail->node
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail = accounts[i][j];
                if(umap.find(mail)==umap.end())
                {
                     //map me daalo agar nhi kra
                    umap[mail] = i;
                }
                else
                {
                    //map me mail already hai to union kro unke indexes me
                    ds.unionByRank(i,umap[mail]);
                }
            }
        }
        vector<vector<string>>mergedMail(n);
        for(auto it:umap)
        {
            string mail = it.first;
             //"johnsmith@mail.com"-0
            //"johnsmith@mail.com"-1 toh 1 ko 0 se connect kro kyuki ye map me already exist karta hai
            //"john00@mail.com" -1 hai to isko ham 1 hi push krenge
            int node = ds.findParent(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            if(mergedMail[i].size()==0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};