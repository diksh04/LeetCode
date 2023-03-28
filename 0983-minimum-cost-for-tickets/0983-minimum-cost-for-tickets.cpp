class Solution {
public:
    int helper(vector<int>& days,vector<int>& costs,int idx,vector<int>& dp)
    {
        if(idx>=days.size())
        {
            return 0;
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        //day 1
        int option1 = costs[0] + helper(days,costs,idx+1,dp);
        
        //day 2
        int i;
        for(i = idx;i<days.size() && days[i] < days[idx]+7;i++)
        {
            //runing i 
        }
            
        int option2 = costs[1] + helper(days,costs,i,dp);
        
        //day 3
        for(i = idx;i<days.size() && days[i]<days[idx]+30;i++)
        {
            //runing i
        }   
        int option3 = costs[2] + helper(days,costs,i,dp);
        
        dp[idx] = min(option1,min(option2,option3));
        return dp[idx];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(366,-1);
        return helper(days,costs,0,dp);
    }
};