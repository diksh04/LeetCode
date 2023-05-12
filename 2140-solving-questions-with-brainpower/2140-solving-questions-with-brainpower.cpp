class Solution {
public:
    long long helper(vector<vector<int>>& questions,int n,int idx,vector<long long>& dp)
    {
        if(idx>=n)
        {
            return 0;
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        long long prof = 0;
        prof = max(questions[idx][0] + helper(questions,n,idx+questions[idx][1]+1,dp),helper(questions,n,idx+1,dp));
        return dp[idx] = prof;
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n,-1);
        return helper(questions,n,0,dp);
    }
};