class Solution {
public:
    void helper(int idx,string output,string s,vector<string> &ans)
    {
        if(idx == s.size())
        {
            ans.push_back(output);
            return;
        }
        if(s[idx]>='0' && s[idx]<='9')
        {
            output.push_back(s[idx]);
            helper(idx+1,output,s,ans);
        }
        else
        {
            char ch1 = tolower(s[idx]);
            char ch2 = toupper(s[idx]);
            output.push_back(ch1);
            helper(idx+1,output,s,ans);
            output.pop_back();
            output.push_back(ch2);
            helper(idx+1,output,s,ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string output = "";
        helper(0,output,s,ans);
        return ans;
    }
};