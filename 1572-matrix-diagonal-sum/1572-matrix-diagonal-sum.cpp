class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        for(int idx=0;idx<mat.size();idx++)
        {
            for(int idx2=0;idx2<mat.size();idx2++)
            {
                if( idx==idx2 || idx+idx2==mat.size()-1)
                {
                    sum+=mat[idx][idx2];
                }
            }
        }
        return sum;
    }
};