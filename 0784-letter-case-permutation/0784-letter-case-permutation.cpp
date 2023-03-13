class Solution {
public:
    vector<string>ans;
    void helper(string s,int idx,string temp)
    {
        if(idx==s.size())
        {
            ans.push_back(temp);
            return;
        }
        if(isdigit(s[idx]))
        {
            temp.push_back(s[idx]);
            helper(s,idx+1,temp);
        }
        else
        {
            //case 1
            string s1 = temp;
            s1.push_back(tolower(s[idx]));
            helper(s,idx+1,s1);
            
            //case2
            string s2 = temp;
            s2.push_back(toupper(s[idx]));
            helper(s,idx+1,s2);
        }
    }
    vector<string> letterCasePermutation(string s) {
        helper(s,0,"");
        return ans;
    }
};