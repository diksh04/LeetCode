class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s;
        for(int i=0;i<s.size()-1;i++)
        {
            t.push_back(t[0]);
            t.erase(0,1);
            if(s==t)
            {
                return true;
            }
        }
        return false;
    }
};