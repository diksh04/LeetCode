class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m*k)
        {
            return -1;
        }
        int low = INT_MAX,high = INT_MIN;
        for(int i=0;i<bloomDay.size();i++)
        {
            low = min(low,bloomDay[i]);
            high = max(high,bloomDay[i]);
        }
        int boqts;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            boqts = 0;
            int count = 0;
            for(int i=0;i<bloomDay.size();i++)
            {
                if(bloomDay[i]<=mid)
                {
                    count++;
                }
                else
                {
                    boqts+=(count/k);
                    count=0;
                }
            }
            boqts+=(count/k);
            if(boqts >= m)
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