class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                ans[i]=pref[i];
            }
            else
            {
                ans[i] = pref[i]^pref[i-1];
            }
        }
        return ans;
    }
};