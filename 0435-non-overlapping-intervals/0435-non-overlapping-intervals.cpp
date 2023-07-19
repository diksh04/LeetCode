class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        // [[1,2][1,3][2,3][3,4]]  -> 1
        int count=-1;
        vector<int>prev = intervals[0];
        for(vector<int>& A: intervals)
        {
            if(A[0] < prev[1] && A[1] <= prev[1])
            {
                count++;
                prev=A;
            }
            else if(A[0] < prev[1] && A[1] > prev[1])
            {
                count++;
            }
            else
            {
                prev = A;
            }
        }
        return count;
    }
};