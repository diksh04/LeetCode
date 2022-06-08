class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count = 0;
        sort(costs.begin(),costs.end());//  1 2 3 4
        int i = 0;
        while(coins>0 && i<costs.size())// 6
        {
            if(costs[i]<=coins)
            {
                count++;
                coins = coins - costs[i];
            }
            i++;
        }
        return count;
    }
};