class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>hash(26,0);
        for(int i=0;i<chars.size();i++)
        {
            hash[chars[i]-'a']++;
        }
        int len = 0;
        for(int i=0;i<words.size();i++)
        {
            string str = words[i];
            vector<int>wordCount(26,0);
            for(char ch:str)
            {
                wordCount[ch-'a']++;
            }
            bool flag = true;
            for(int i=0;i<26;i++)
            {
                if(hash[i]<wordCount[i])
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag==true)
            {
                len+=str.size();
            }
        }
        return len;
    }
};