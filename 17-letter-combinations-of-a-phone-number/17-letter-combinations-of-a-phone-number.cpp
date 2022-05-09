class Solution {
public:
    vector<string> getkpc(string digits) {
        string codes[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    if(digits.size()==0)
    {
        return {""};
    }
    char ch = digits[0]-'0';
   vector<string> restofstring = getkpc(digits.substr(1));
   vector<string> ans;
   string codesforch = codes[ch];
   for(int j=0;j<codesforch.size();j++)
   {
       for(int i=0; i<restofstring.size();i++)
       {
           ans.push_back(codesforch[j] + restofstring[i] );
       }
       
   }
   return ans;
    }
    vector<string> letterCombinations(string digits){
        if(digits=="")
        {
            return {};
        }
            vector<string> ans = getkpc(digits);
            return ans;
    }
};