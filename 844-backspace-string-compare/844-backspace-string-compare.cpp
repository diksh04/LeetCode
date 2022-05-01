class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;
        vector<char>a1;
        vector<char>a2;
        for(int i=0;i<s.size();i++)
        {
            char ch1 = s[i];
            if(ch1=='#' && st1.size()>0)
            {
                st1.pop();
            }
            else if(ch1!='#')
            {
                st1.push(ch1);
            }
        }
        for(int i=0;i<t.size();i++)
        {
            char ch2 = t[i];
            if(ch2=='#' && st2.size()>0)
            {
                st2.pop();
            }
            else if(ch2!='#')
            {
                st2.push(ch2);
            }
        }
        while(st1.size()>0)
        {
            a1.push_back(st1.top());
            st1.pop();
        }
        while(st2.size()>0)
        {
            a2.push_back(st2.top());
            st2.pop();
        }
        if(a1!=a2)
        {
            return false;
        }
        return true;
    }
};