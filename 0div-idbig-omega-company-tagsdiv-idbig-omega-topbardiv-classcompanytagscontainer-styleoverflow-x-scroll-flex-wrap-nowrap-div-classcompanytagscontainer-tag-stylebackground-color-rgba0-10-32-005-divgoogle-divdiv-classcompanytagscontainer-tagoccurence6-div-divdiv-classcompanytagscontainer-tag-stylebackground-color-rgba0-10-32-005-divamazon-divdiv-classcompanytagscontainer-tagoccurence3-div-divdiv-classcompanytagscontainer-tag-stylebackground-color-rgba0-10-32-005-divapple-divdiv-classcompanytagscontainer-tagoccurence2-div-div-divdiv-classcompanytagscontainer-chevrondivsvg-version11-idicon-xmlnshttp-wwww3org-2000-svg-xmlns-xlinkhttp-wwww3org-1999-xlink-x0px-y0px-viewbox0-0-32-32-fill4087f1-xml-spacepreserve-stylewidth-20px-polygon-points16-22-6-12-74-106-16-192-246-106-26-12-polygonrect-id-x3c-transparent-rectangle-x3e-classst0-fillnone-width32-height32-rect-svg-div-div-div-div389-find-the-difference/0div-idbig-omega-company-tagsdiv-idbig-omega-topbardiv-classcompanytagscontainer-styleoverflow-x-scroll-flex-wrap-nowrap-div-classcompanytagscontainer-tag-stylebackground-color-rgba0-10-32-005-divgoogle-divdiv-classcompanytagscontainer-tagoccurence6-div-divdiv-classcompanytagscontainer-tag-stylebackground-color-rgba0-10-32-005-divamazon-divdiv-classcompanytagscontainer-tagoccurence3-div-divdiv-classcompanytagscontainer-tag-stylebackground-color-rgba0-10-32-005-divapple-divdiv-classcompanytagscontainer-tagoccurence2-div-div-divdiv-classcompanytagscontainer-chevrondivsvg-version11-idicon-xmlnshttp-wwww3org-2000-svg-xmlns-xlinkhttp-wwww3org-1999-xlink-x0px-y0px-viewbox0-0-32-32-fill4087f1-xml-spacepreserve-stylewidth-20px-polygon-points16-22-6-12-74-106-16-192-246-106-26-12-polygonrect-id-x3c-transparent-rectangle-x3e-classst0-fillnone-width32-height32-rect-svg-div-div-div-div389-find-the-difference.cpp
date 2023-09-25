class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>vec(26,0);
        for(int i=0;i<t.size();i++)
        {
            vec[t[i]-'a']++;
        }
        //
        for(int i=0;i<s.size();i++)
        {
            vec[s[i]-'a']--;
        }
        char ch = 'a';
        for(int i=0;i<26;i++)
        {
            if(vec[i]==1)
            {
                ch+=i;
                break;
            }
        }
        return ch;
    }
};