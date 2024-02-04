class Solution {
public:
    string largestOddNumber(string num) {
        int i=num.size()-1;
        while(i>=0)
        {
            if((int)(num[i]-'0')%2!=0)
            {
                break;
            }
            i--;
        }
        return num.substr(0,i+1);
    }
};