bool compare(vector<int> b1 , vector<int>b2)
{
    return b1[1]>b2[1];
}
class Solution {
public:
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare); 
        
        int sum = 0,ans=0,i;
        for(i = 0; i<boxTypes.size() ; i++ )
        {
            if(sum+boxTypes[i][0]<=truckSize)
            {
                sum+=boxTypes[i][0];
                ans+=boxTypes[i][0]*boxTypes[i][1];
            }
            else
            {
                ans += (truckSize-sum)*boxTypes[i][1];
                break;
            }
        }
        return ans;
    }
};