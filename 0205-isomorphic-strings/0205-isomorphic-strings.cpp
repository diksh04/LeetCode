class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char,char>mp1;
        map<char,bool>mp2;
        for(int i=0;i<s.size();i++)
        {
            char ch1 = s[i];
            char ch2 = t[i];
            if(mp1.contains(ch1))
            {
                if(mp1[ch1] != ch2)
                {
                    return false;
                }
            }
            else
            {
                if(mp2.contains(ch2))
                {
                    return false;
                }
                else
                {
                    mp1[ch1] = ch2;
                    mp2[ch2] = true;
                }
            }
        }
        return true;
    }
};