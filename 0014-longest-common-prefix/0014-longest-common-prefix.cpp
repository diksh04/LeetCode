class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(),strs.end());// flight,flow,flower
        string x = strs[0];//flight
        string y = strs[strs.size()-1];//flower
        for(int i=0;i<x.size();i++)
        {
            if(x[i]==y[i])
            {
                ans+=x[i];//fl
            }
            else
            {
                break;
            }
        }
        return ans;//fl
    }
};