class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            map<char,int>umap;
            multiset<int>st;
            for(int j=i;j<n;j++)
            {
                if(umap.find(s[j])!=umap.end())
                {
                    st.erase(st.find(umap[s[j]]));
                }
                umap[s[j]]++;
                st.insert(umap[s[j]]);
                sum+=(*st.rbegin() - *st.begin());
            }
        }
        return sum;
    }
};