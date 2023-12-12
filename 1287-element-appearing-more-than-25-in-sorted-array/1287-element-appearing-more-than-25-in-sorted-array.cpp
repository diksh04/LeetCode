class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int range = arr.size()/4;
        int ele=arr[0],cnt = 1;
        int mxCount = 0;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]==arr[i-1])
            {
                cnt++;
            }
            else
            {
                if(cnt > mxCount)
                {
                    mxCount = cnt;
                    ele = arr[i-1];
                }
                cnt = 1;
            }
        }
        if(cnt > mxCount)
        {
            mxCount = cnt;
            ele = arr[arr.size()-1];
        }
        return ele;
    }
};