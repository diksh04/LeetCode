class Solution {
public:
     static bool comp(pair<int,int>&p1,pair<int,int>&p2){
     
     return p1.second > p2.second;
 }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int ans = 0,start=0;
        vector<pair<int,int>>p;
        for(int i=0;i<plantTime.size();i++)
        {
            p.push_back({plantTime[i],growTime[i]});
        }
        sort(p.begin(),p.end(),comp);
        
        for(int i=0;i<plantTime.size();i++){
           start += p[i].first;
           ans=max(ans,start + p[i].second);
        }
        return ans;
    }
};