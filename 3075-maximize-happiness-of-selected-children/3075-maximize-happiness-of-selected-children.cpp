class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        long long ans = 0;
        int cntDec = 0;
        for(int i=happiness.size()-1;i>=0 && k > 0;i--)
        {
            happiness[i] = happiness[i] + cntDec;
            if(happiness[i]>0)
            {
                ans += (happiness[i]);
                // cout<<ans<<" "<<cntDec<<" "<<k<<endl;
                cntDec--;
                k--;
            }
        }
        return ans;
    }
};