class DisjointSet{
    vector<int>parent,rank;
    public:
        DisjointSet(int n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++)
            {
                parent[i] = i;
            }
        }
        int findUPar(int node)
        {
            if(node==parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
        void unionByRank(int u,int v)
        {
            int ultiU = findUPar(u);
	        int ultiV = findUPar(v);
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
        unordered_map<string,int>umap;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail = accounts[i][j];
                if(umap.find(mail)==umap.end())
                {
                    umap[mail] = i;
                }
                else
                {
                    ds.unionByRank(i,umap[mail]);
                }
            }
        }
        vector<vector<string>>mergedMail(n);
        for(auto it:umap)
        {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            if(mergedMail[i].size()==0) continue;
            string name = accounts[i][0];
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(name);
            for(auto it:mergedMail[i]) temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};