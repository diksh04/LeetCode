class Solution {
public:
    static bool compare(vector<int>& p1,vector<int>& p2)
    {
        return p1[1] < p2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),compare);
        int count = 1;
        auto p1 = pairs[0];
        for(int i=1;i<pairs.size();i++)
        {
            auto p2 = pairs[i];
            if(p2[0]>p1[1])
            {
                count++;
                p1 = p2;
            }
        }
        return count;
    }
};