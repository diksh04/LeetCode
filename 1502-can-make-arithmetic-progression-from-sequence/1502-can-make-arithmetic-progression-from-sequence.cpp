class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if(arr.size()<=2)
        {
            return true;
        }
        sort(arr.begin(),arr.end());
        int dif = arr[1]-arr[0];
        for(int i=2;i<arr.size();i++)
        {
            if(dif != (arr[i]-arr[i-1]))
            {
                return false;
            }
        }
        return true;
    }
};