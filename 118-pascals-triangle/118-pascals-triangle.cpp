class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int i=0;i<numRows;i++)
        {
            int var = 1;
            vector<int>ans;
            for(int j=0;j<=i;j++)
            {
                ans.push_back(var);
                var = var*(i-j)/(j+1);
            }
            res.push_back(ans);
        }
        return res;
    }
};