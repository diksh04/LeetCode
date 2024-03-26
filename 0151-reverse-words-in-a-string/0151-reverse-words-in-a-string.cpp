class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        
        string ans;
        int i=0;
        while(i<n)
        {
            while(i<n && s[i]==' ')
            {
                i++;
            }
            if(i>=n) break;
            int j = i;
            while(j<n && s[j]!=' ')
            {
                j++;
            }
            string sub = s.substr(i,j-i);
            if(ans.size()==0) ans = sub;
            else ans = sub + " " + ans;
            i = j;
            cout<<i<<" ";
        }
        return ans;
    }
};