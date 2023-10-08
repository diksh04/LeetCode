class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ch = upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        if(ch == letters.size())
        {
            return letters[0];
        }
        return letters[ch];
    }
    // a a b b c c d d e e f    target = c,output = d
    // 0 1 2 3 4 5 6 7 8 9 10
    //           r lm    
    //mid1 = 0+10/2=5,mid2 = 6+10/2 = 8,mid = 6+7/2 = 6
    // ans = 6
};