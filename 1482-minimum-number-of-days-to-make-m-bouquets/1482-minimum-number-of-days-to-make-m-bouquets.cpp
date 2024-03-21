class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k) return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int boqts=0,cnt = 0;
            for(int i=0;i<bloomDay.size();i++)
            {
                if(bloomDay[i]<=mid)
                {
                    cnt++;
                }
                else
                {
                    boqts+=(cnt/k);
                    cnt = 0;
                }
            }
            boqts+=(cnt/k);
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