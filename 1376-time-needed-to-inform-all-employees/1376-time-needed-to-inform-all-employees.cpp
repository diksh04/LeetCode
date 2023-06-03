class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        queue<int>q;
        q.push(headID);
        int ans = informTime[headID];
        vector<vector<int>>g(n);
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i]!=-1)
            {
                g[manager[i]].push_back(i);
            }
        }
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(int i=0;i<g[cur].size();i++)
            {
                int next = g[cur][i];
                q.push(next);
                informTime[next] = informTime[next] + informTime[cur];
                ans = max(ans, informTime[next]);
            }
        }
        return ans;
    }
};