class Solution {
public:
    bool check(string word,vector<int>tar)
    {
        for(char ch:word)
        {
            if(tar[ch-'a']!=0)
            {
                tar[ch-'a']--;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(tar[i]>0)
            {
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<int>tar(26);
        for(string str : words2)
        {
            vector<int>temp(26,0);
            for(char ch:str)
            {
                temp[ch-'a']++;
                // tar[ch-'a'] = max(tar[ch-'a'],temp[ch-'a']);
            }
            for(int i=0;i<26;i++)
            {
                tar[i] = max(tar[i],temp[i]);
            }
        }
        for(string str:words1)
        {
            if(check(str,tar))
            {
                ans.push_back(str);
            }
        }
        return ans;
    }
};