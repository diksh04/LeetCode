class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>a1(26,0);
        vector<int>a2(26,0);
        for(int i=0;i<ransomNote.size();i++)
        {
            a1[ransomNote[i]-'a']++;
        }
        for(int i=0;i<magazine.size();i++)
        {
            a2[magazine[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(a1[i]>a2[i])
            {
                return false;
            }
        }
        return true;
    }
};