class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        set<string>s;
        int count = 0;
        for(int i=0;i<words.size();i++)
        {
            string temp = words[i];
            reverse(temp.begin(),temp.end());
            if(s.find(temp)!=s.end())
            {
                count++;
            }
            else
            {
                s.insert(words[i]);
            }
        }
        return count;
    }
};