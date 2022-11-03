class Solution {
public:
    int check(string &s1,string &s2)
    {
        int count = 0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                count++;
            }
        }
        return count;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(int i=0;i<queries.size();i++)
        {
            for(int j=0;j<dictionary.size();j++)
            {
                int ct = check(queries[i],dictionary[j]);
                if(ct<=2)
                {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};