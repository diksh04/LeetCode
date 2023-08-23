class Solution {
public:
    typedef pair<int,char>P;//freq,char
    string reorganizeString(string s) {
       int n = s.size();
        vector<int>arr(26,0);
        for(int i=0;i<n;i++)
        {
            arr[s[i]-'a']++;
            if(arr[s[i]-'a']>(n+1)/2)
            {
                return "";
            }
        }
        priority_queue<P,vector<P>>pq;
        for(char ch='a';ch<='z';ch++)
        {
            if(arr[ch-'a']>0)
            {
                pq.push({arr[ch-'a'],ch});
            }
        }
        string ans = "";
        while(pq.size()>=2)
        {
            auto P1 = pq.top();
            pq.pop();
            auto P2 = pq.top();
            pq.pop();
            ans.push_back(P1.second);
            P1.first--;
            ans.push_back(P2.second);
            P2.first--;
            if(P1.first > 0)
            {
                pq.push(P1);
            }
            if(P2.first > 0)
            {
                pq.push(P2);
            }
        }
        if(!pq.empty())
        {
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};