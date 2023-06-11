class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>ans(num_people,0);
        int i=0;
        int candy = 1;
        while(i<ans.size())
        {
            if(candies < candy)
            {
                ans[i]+=candies;
                break;
            }
            ans[i]+=candy;
            candies-=candy;
            i = (i+1)%num_people;
            candy++;
        }
        return ans;
    }
};