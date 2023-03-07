class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        long long low = 0;
        long long high = 1LL*time[time.size()-1]*totalTrips;
        long long minTime = 1LL*time[time.size()-1]*totalTrips;
        while(low<high)
        {
            long long tempTime = 0;
            long long mid = (low+high)/2;
            for(int i=0;i<time.size();i++)
            {
                tempTime+=(mid/time[i]);
            }
            if(tempTime>=totalTrips)
            {
                minTime = min(minTime,mid);
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return minTime;
    }
};
 // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
     