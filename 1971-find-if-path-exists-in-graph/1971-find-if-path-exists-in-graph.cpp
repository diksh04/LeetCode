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
            if(node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
        void unionByRank(int u,int v)
        {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] > rank[ulp_v])
            {
                parent[ulp_v] = ulp_u;
            }
            else if(rank[ulp_u] < rank[ulp_v])
            {
                parent[ulp_u] = ulp_v;
            }
            else
            {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u)!=ds.findUPar(v))
            {
                ds.unionByRank(u,v);
            }
        }
        if(ds.findUPar(source)==ds.findUPar(destination)) return true;
        return false;
    }
};