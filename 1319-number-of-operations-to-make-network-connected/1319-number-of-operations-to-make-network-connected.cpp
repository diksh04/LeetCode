class Solution {
public:
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtra = 0;
        for(auto it:connections)
        {
            int u = it[0];
            int v = it[1];
            if(ds.findParent(u)==ds.findParent(v))
            {
                //extra edge
                cntExtra++;
            }
            else
            {
                ds.unionByRank(u,v);
            }
        }
        int cntComp = 0;
        for(int i=0;i<n;i++)
        {
            if(ds.findParent(i)==i)
            {
                cntComp++;
            }
        }
        int ans = cntComp-1;
        if(cntExtra >= ans) return ans;
        return -1;
    }
};