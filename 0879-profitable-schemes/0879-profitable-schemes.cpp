class Solution {
public:
    int dp[102][102][102];
    int mod=1e9+7;
    int helper(int idx,int people,int prof,int n,int minProfit,vector<int>& group, vector<int>& profit)
    {
        if(idx==group.size())
        {
            if(prof >= minProfit && n >=people)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if(n < people)
        {
            return 0;
        }
        if(dp[idx][people][prof]!=-1)
        {
            return dp[idx][people][prof];
        }
        int pick=0,notpick=0;
        notpick = helper(idx+1,people,prof,n,minProfit,group,profit);
        pick = helper(idx+1,people+group[idx],min(prof+profit[idx],minProfit),n,minProfit,group,profit);
        return dp[idx][people][prof] = (pick%mod + notpick%mod)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,0,n,minProfit,group,profit);
    }
};