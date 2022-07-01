bool compare(vector<int>v1,vector<int>v2)
    {
        return v1[1]>v2[1];
    }
class Solution {
public:
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int units = 0,i=0;
        while(truckSize>0 && i<boxTypes.size())
        {
            if(boxTypes[i][0]<=truckSize)
            {
                units+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }
            else
            {
                int take = truckSize;
                truckSize=0;
                units+=take*boxTypes[i][1];
            }
            i++;
        }
        return units;
    }
};
