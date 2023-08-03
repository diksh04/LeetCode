class Solution {
public:
    const vector<string>codes = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>getKpc(string digits)
    {
        if(digits.size()==0)
        {
            return {""};
        }
        char ch = digits[0];
        vector<string>ros = getKpc(digits.substr(1));
        vector<string>ans;
        string codesforch = codes[ch-'2'];
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
        if(digits=="")
        {
            return {};
        }
        vector<string>ans = getKpc(digits);
        return ans;
    }
};