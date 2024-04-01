class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(i<s.size() && s[i]==' ')
        {
            i++;
        }
        if(i==s.size()) return 0;
        int sign = 1;
        if(s[i]=='-')
        {
            sign = -1;
            i++;
        }
        else if(s[i]=='+') i++;
        long long num = 0;
        while(i<s.size())
        {
            if(s[i]>='0' && s[i]<='9')
            {
                num = num * 10 + (s[i]-'0');
                if(sign* num > INT_MAX)
                {
                    return INT_MAX;
                }
                else if(sign * num < INT_MIN)
                {
                    return INT_MIN;
                }
            }
            else break;
            i++;
        }
        num*=sign;
        return num;
    }
};