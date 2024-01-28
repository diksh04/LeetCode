class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int day = 1,load = 0;
            for(int i=0;i<weights.size();i++)
            {
                if(load + weights[i]<=mid)
                {
                    load+=weights[i];
                }
                else
                {
                    day++;
                    load=weights[i];
                }
            }
            if(day <= days)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;
    }
};