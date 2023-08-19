class Solution {
public:
    bool isValid(string s)
    {
        if(s[0]=='0')
        {
            return false;
        }
        int num = stoi(s);
        if(num >=0 && num<=255)
        {
            return true;
        }
        return false;
    }
    void helper(string s,int idx,int part,string str,vector<string>& ans)
    {
        if(idx==s.size())
        {
            if(part==4)
            {
                ans.push_back(str.substr(0,str.size()-1));
            }
            return;
        }
        //if i want only 1 char in 1st part
        helper(s,idx+1,part+1,str+s[idx]+".",ans);
        
        //if i want 2 chars in my 1st part
        if(idx+1 < s.size() && isValid(s.substr(idx,2)))
        {
            helper(s,idx+2,part+1,str+s.substr(idx,2)+".",ans);
        }
        
        //if i want 3 char in my 1st part
        if(idx+2 < s.size() && isValid(s.substr(idx,3)))
        {
            helper(s,idx+3,part+1,str+s.substr(idx,3)+".",ans);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        if(s.size()>12 || s.size()<4)
        {
            return ans;
        }
        helper(s,0,0,"",ans);//string,idx,part,string to store different ip,resultant string
        return ans;
    }
};
