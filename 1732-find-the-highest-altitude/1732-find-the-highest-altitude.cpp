class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int curr = 0;
        for(int i=0;i<gain.size();i++)
        {
            curr+=gain[i];
            maxAltitude = max(maxAltitude,curr);
        }
        return maxAltitude;
    }
};