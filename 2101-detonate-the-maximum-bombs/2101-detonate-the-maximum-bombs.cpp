class Solution {
public:
    int bfs(vector<vector<int>>& bombs,int src)
    {
        int n = bombs.size();
        vector<bool>vis(n,false);
        queue<pair<int,pair<int,int>>>q;
        q.push({bombs[src][2],{bombs[src][0],bombs[src][1]}});
        vis[src] = true;
        int count = 1;
        while(!q.empty())
        {
            long long int x = q.front().second.first,y = q.front().second.second;
            long long int r = q.front().first;
            q.pop();
            for(int i=0;i<n;i++)
            {
                if(!vis[i])
                {
                    long long int x1 = bombs[i][0],y1 = bombs[i][1];
                    long long int x2 = abs(x-x1),y2 = abs(y-y1);
                    if(x2*x2 + y2*y2 <= r*r)
                    {
                        count++;
                        vis[i] = true;
                        q.push({bombs[i][2],{bombs[i][0],bombs[i][1]}});
                    }
                }
            }
        }
        return count;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        int mx = 0;
        for(int i=0;i<n;i++)
        {
            mx = max(mx,bfs(bombs,i));
        }
        return mx;
    }
};