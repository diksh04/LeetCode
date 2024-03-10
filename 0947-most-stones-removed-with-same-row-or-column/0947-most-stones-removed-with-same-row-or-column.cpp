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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(auto it:stones)
        {
            maxRow = max(it[0],maxRow);
            maxCol = max(it[1],maxCol);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int,int>stoneNodes;//to get unique ultimate parent for unique components
        for(auto it:stones)
        {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow,nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int cnt = 0;
        for(auto it:stoneNodes)
        {
            if(ds.findParent(it.first) == it.first)
            {
                cnt++;
            }
        }
        return n - cnt;
        
    }
};