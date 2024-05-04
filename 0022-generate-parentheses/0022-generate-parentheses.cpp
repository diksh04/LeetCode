class Solution {
public:
    void helper(string output,int open,int close,vector<string>& ans)
    {
        if(open == 0 && close == 0)
        {
            ans.push_back(output);
            return;
        }
        if(open!=0)
        {
            string output2 = output;
            output2.push_back('(');
            helper(output2,open-1,close,ans);
        }
        if(open < close)
        {
            string output2 = output;
            output2.push_back(')');
            helper(output2,open,close-1,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        vector<string>ans;
        string output = "";
        helper(output,open,close,ans);
        return ans;
    }
};