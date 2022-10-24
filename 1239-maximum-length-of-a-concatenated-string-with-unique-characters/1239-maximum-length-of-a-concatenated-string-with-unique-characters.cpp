class Solution {
public:
    void helper(int idx,vector<int>& vis,vector<string>& arr,int curlen,int& maxlen)
    {
        if(idx<0)
        {
            maxlen = max(maxlen,curlen);
            return;
        }
        int n = arr[idx].size();
        int flag = 0;
        vector<int>t = vis;
        for(int i=0;i<n;i++)
        {
            char ch = arr[idx][i];
            if(t[ch-'a']==1)
            {
                flag = 1;
                break;
            }
            t[ch-'a'] = 1;
        }
        if(flag == 0)
        {
            helper(idx-1,t,arr,curlen+arr[idx].size(),maxlen);//take string
        }
        helper(idx-1,vis,arr,curlen,maxlen);//not take
    }
    int maxLength(vector<string>& arr) {
        int curlen = 0;
        int n = arr.size();
        vector<int>vis(26,0);
        int maxlen = 0;
        helper(n-1,vis,arr,curlen,maxlen);
        return maxlen;
    }
};