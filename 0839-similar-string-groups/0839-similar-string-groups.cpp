class Solution {
public:
    vector<int>adj[305];
    int vis[305];
    void dfs(int node)
    {
        vis[node] = 1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it);
            }
        }
    }
    bool isSimilar(string s1,string s2)
    {
        int count = 0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                count++;
                if(count>2)
                {
                    return false;
                }
            }
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int pairs = 0;
        for(int i=0;i<strs.size();i++)
        {
            for(int j=i+1;j<strs.size();j++)
            {
                if(isSimilar(strs[i],strs[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<strs.size();i++)
        {
            if(!vis[i])
            {
                dfs(i);
                pairs++;
            }
        }
        return pairs;
    }
};