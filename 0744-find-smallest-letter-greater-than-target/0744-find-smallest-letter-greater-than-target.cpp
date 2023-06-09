class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0,right = letters.size()-1,ans = 0;
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            if(letters[mid]==target)
            {
                left = mid+1;
            }
            else if(letters[mid]<target)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
                ans = mid;
            }
        }
        return letters[ans];
    }
    // a a b b c c d d e e f    target = c,output = d
    // 0 1 2 3 4 5 6 7 8 9 10
    //           r lm    
    //mid1 = 0+10/2=5,mid2 = 6+10/2 = 8,mid = 6+7/2 = 6
    // ans = 6
};