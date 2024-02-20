class Solution {
public:
    void helper(int idx,string &s,string output,vector<string>& ans)
    {
        if(idx==s.size())
        {
            ans.push_back(output);
            return;
        }
        if(!isalpha(s[idx]))
        {
            output.push_back(s[idx]);
            helper(idx+1,s,output,ans);
        }
        else
        {
            char ch1 = tolower(s[idx]);
            char ch2 = toupper(s[idx]);
            helper(idx+1,s,output+ch1,ans);
            helper(idx+1,s,output+ch2,ans);
        }
        return;
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string output;
        helper(0,s,output,ans);
        return ans;
    }
};