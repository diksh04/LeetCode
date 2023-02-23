#define pi pair<int,int>
class Solution {
public:
    
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>>project;
        for(int i=0;i<n;i++)
        {
            project.push_back({profits[i],capital[i]});
        }
        sort(project.begin(),project.end(),[&](pi a,pi b){
            return a.second < b.second; 
        });
        priority_queue<int>pq;
        int i=0;
        while(k)
        {
            while(i<n && project[i].second<=w)
            {
                pq.push(project[i++].first);
            }
            if(!pq.empty())
            {
                w+=pq.top();
                pq.pop();
            }
            k--;
        }
        return w;
    }
};