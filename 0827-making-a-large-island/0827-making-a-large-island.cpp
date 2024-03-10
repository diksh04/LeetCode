class DisjointSet {

public:
  vector<int> size, parent;
  DisjointSet(int n) {
    size.resize(n + 1, 1);
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
    }
  }
  int findParent(int node) {
    if (node == parent[node])
      return node;
    return parent[node] = findParent(parent[node]);
  }
  void unionBySize(int u, int v) {
    int ultimateParentU = findParent(u);
    int ultimateParentV = findParent(v);
    if (ultimateParentU == ultimateParentV) {
      // belonging to same component
      return;
    }
    if (size[ultimateParentU] < size[ultimateParentV]) {
      parent[ultimateParentU] = ultimateParentV;
      size[ultimateParentV] += size[ultimateParentU];
    } else {
      parent[ultimateParentV] = ultimateParentU;
      size[ultimateParentU] += size[ultimateParentV];
    }
  }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)  continue;
                int dx[4] = {-1,0,1,0};
                int dy[4] = {0,-1,0,1};
                for(int k=0;k<4;k++)
                {
                    int nrow = i + dx[k];
                    int ncol = j + dy[k];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1)
                    {
                        int nodeNo = i * n + j;
                        int adjNodeNo = nrow * n + ncol;
                        ds.unionBySize(nodeNo,adjNodeNo);    
                    }
                }
            }
        }
        int mx = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) continue;
                int dx[4] = {-1,0,1,0};
                int dy[4] = {0,-1,0,1};
                set<int>components;
                for(int k=0;k<4;k++)
                {
                    int nrow = i + dx[k];
                    int ncol = j + dy[k];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1)
                    {
                        components.insert(ds.findParent(nrow*n+ncol));  
                    }
                }
                int sizeTotal = 0;
                for(auto it:components)
                {
                    sizeTotal+=ds.size[it];
                }
                mx = max(mx,sizeTotal+1);
            }
        }
//         what if grid has all 1's
        for(int cellNo=0;cellNo<n*n;cellNo++)
        {
            mx = max(mx,ds.size[ds.findParent(cellNo)]);
        }
        return mx;
    }
};