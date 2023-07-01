class Solution {
public:
    int helper(vector<int>& cookies,int i,vector<int>& choc)
    {
        if(i==cookies.size())
        {
            int ans = 0;
            for(auto it: choc)
            {
                ans = max(ans,it);
            }
            return ans;
        }
        int mn = INT_MAX;
        for(int j=0;j<choc.size();j++)
        {
            choc[j]+=cookies[i];
            mn = min(mn,helper(cookies,i+1,choc));
            choc[j]-=cookies[i];
            
        }
        return mn;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>choc(k);
        return helper(cookies,0,choc);
    }
};