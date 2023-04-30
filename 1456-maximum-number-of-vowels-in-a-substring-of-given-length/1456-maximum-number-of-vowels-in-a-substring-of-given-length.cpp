class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int vowels = 0,maxLen = INT_MIN;
        for(int i=0;i<k;i++)
        {
            if(isVowel(s[i]))
            {
                vowels++;
            }
        }
        maxLen = max(maxLen,vowels);
        for(int i = k;i < s.size(); i++)
        {
            if(isVowel(s[i-k]))
            {
                vowels--;
            }
            if(isVowel(s[i]))
            {
                vowels++;
            }
             maxLen = max(maxLen,vowels);
        }
        return maxLen;
       
    }
};