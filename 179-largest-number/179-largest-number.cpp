class Solution {
public:
    static bool compare(string &s1,string &s2)
    {
        return (s1+s2) > (s2+s1);
    }
    string largestNumber(vector<int>& nums) {
        vector<string>str;
        for(int i=0;i<nums.size();i++)
        {
            str.push_back(to_string(nums[i]));
        }
        sort(str.begin(),str.end(),compare);
        string s="";
        if(str[0]=="0")
        {
            return "0";
        }
        for(auto x:str)
        {
            s+=x;
        }
        return s;
    }
};