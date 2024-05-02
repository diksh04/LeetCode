class Solution {
public:
    vector<string>codes = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> helper(string digits)
    {
        if(digits == "")
        {
            return {""};
        }
        char ch = digits[0];
        string codesforch = codes[ch-'2'];
        vector<string>ros = helper(digits.substr(1));
        vector<string>ans;
        for(int i=0;i<codesforch.size();i++)
        {
            for(int j=0;j<ros.size();j++)
            {
                ans.push_back(codesforch[i]+ros[j]);
            }
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        return helper(digits);
    }
};