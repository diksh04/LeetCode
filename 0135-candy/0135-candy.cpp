class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>candy(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                candy[i] = candy[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                candy[i] = max(candy[i],candy[i+1]+1);
            }
        }
        int candies = 0;
        for(auto it:candy)
        {
            candies+=it;
        }
        return candies;
    }
};
// arr[] = 1 0 2
// left[] = 1 1 2
// right[] = 2 1 2  

