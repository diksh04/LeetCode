class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int count = 0;
        int n = img1.size();
        vector<pair<int,int>>v1,v2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(img1[i][j]==1)
                {
                    v1.push_back({i,j});
                }
                if(img2[i][j]==1)
                {
                    v2.push_back({i,j});
                }
            }
        }
        map<pair<int,int>,int>mp;
        for(auto it1: v1)
        {
            for(auto it2: v2)
            {
                int a = it2.first-it1.first;
                int b = it2.second-it1.second;
                mp[{a,b}]++;
                count = max(count,mp[{a,b}]);
            }
        }
        return count;
    }
};