class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = piles[0];
        for(int i=1;i<piles.size();i++)
        {
            right = max(right,piles[i]);
        }
        long mid,hours;
        while(left<=right)
        {
            mid = left + (right-left)/2;
            hours=0;
            for(int i=0;i<piles.size();i++)
            {
                int x = (piles[i]/mid) + (piles[i]%mid!=0);
                hours+=x;
            }
            if(hours>h)
            {
                left = mid+1; 
            }
            else
            {
                right = mid-1;
            }
        }
        return left;
    }
};