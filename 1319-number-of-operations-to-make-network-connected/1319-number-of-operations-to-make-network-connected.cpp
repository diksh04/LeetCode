class Solution {
public:
    class DisjointSet{
        vector<int>rank,parent;
        public:
            DisjointSet(int n)
            {
                rank.resize(n,0);
                parent.resize(n);
                for(int i=0;i<n;i++)
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtra = 0;
        for(auto it:connections)
        {
            if(ds.findUPar(it[0]) == ds.findUPar(it[1]))
            {
                cntExtra++;
            }
            else
            {
                ds.unionByRank(it[0],it[1]);
            }
        }
        int cntComps = 0;
        for(int i=0;i<n;i++)
        {
            if(ds.findUPar(i) == i)
            {
                cntComps++;
            }
        }
        int ans = cntComps-1;
        if(cntExtra >= ans) return ans;
        return -1;
    }
};