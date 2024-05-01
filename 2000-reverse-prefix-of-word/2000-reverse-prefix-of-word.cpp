class Solution {
public:
    string reversePrefix(string word, char ch) {
        int charIdx = word.find(ch);
        if(charIdx == -1)
        {
            return word;
        }
        string ans = "";
        for(int i=charIdx;i>=0;i--)
        {
            ans+=word[i];
        }
        for(int i=charIdx+1;i<word.size();i++)
        {
            ans+=word[i];
        }
        return ans;
    }
};