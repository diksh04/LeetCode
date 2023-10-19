class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "";
        string s2 = "";
        for(int i=0;i<s.size();i++)
        {
            if(!s1.empty() && s[i]=='#' )
            {
                s1.pop_back();
            }
            else if(s[i]!='#')
            {
                 s1+=s[i];
            }
            else
            {
               continue;
            }
        }
        for(int i=0;i<t.size();i++)
        {
            if(!s2.empty() && t[i]=='#' )
            {
                s2.pop_back();
            }
            else if(t[i]!='#')
            {
                 s2+=t[i];
            }
            else
            {
               continue;
            }
        }
        // "y#fo##f"
        // f
        // "y#f#o##f"
        // 
        cout<<s1<<" "<<s2;
        return s1 == s2;
    }
};