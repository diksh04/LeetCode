class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>umap;
        for(int i=0;i<arr.size();i++)
        {
            umap[arr[i]].push_back(i);
        }
        vector<int>visited(arr.size(),false);
        queue<int>q;
        q.push(0);
        visited[0] = true;
        int jumps = 0;
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                int idx = q.front();
                q.pop();
                if(idx == arr.size()-1)
                {
                    return jumps;
                }
                
                vector<int>& temp = umap[arr[idx]];
                temp.push_back(idx+1);
                temp.push_back(idx-1);
                for(auto ele : temp)
                {
                    if(ele>=0 && ele<arr.size() && !visited[ele])
                    {
                        q.push(ele);
                        visited[ele] = true;
                    }
                }
                temp.clear();
                
                
            }
            jumps++;
        }
        return -1;
        
    }
};