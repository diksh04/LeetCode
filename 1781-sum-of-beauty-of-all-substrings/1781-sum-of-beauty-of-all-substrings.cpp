class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            map<char,int>mp;
            multiset<int>st;
            for(int j=i;j<n;j++)
            {
                if(mp.find(s[j])!=mp.end())
                {
                    st.erase(st.find(mp[s[j]]));
                }
                mp[s[j]]++;
                st.insert(mp[s[j]]);
                sum+=(*st.rbegin() - *st.begin());
            }
        }
        return sum;
    }
};