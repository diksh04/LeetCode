class Solution {
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[1]-a[0] > b[1]-b[0];           // a[1]-a[0] is profit for candidate A
    } 
public: 
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum = 0;
        sort(costs.begin(),costs.end(),compare);
        for(int i=0;i<costs.size()/2;i++)
        {
            sum+=costs[i][0];
        }
        for(int i=costs.size()/2;i<costs.size();i++)
        {
            sum+=costs[i][1];
        }
        return sum;
    }
};
// 0 2