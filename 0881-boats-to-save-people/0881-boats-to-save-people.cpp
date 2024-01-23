class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int lo=0,hi=people.size()-1;
        int cnt = 0;
        while(lo<=hi)
        {
            if(people[lo]+people[hi]<=limit)
            {
                cnt++;
                lo++;
                hi--;
            }
            else
            {
                cnt++;
                hi--;
            }
        }
        return cnt;
    }
};