class Solution {
public:
    bool isPalindrome(string s,int low,int high)
    {
        while(low<high)
        {
            if(s[low]!=s[high])
            {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    void helper(int idx,string s,vector<string>& temp,vector<vector<string>>& ans
               )
    {
        if(idx==s.size()) 
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<s.size();i++)
        {
            if(isPalindrome(s,idx,i))
            {
                temp.push_back(s.substr(idx,i-idx+1));
                helper(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>ans;
        vector<string>temp;
        helper(0,s,temp,ans);
        return ans;
    }
};