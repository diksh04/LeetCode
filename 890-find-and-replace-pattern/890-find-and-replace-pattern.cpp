class Solution {
public:
    //mapped both elments in both vectors
    // eg. words[i] =  "a b c" , pattern[i] = "a b b"
    //     a->b , b->a
    //     b->b , b->b  false
    //     c->b  b->c
    
    bool match(string word,string pattern)
    {
        vector<char>p(26);
        vector<char>w(26);
        for(int i=0;i<word.size();i++)
        {
            char wdch = word[i];
            char ptch = pattern[i];
            if(p[ptch-'a']==0)
            {
                p[ptch-'a']=wdch;
            }
            if(w[wdch-'a']==0)
            {
                w[wdch-'a']=ptch;
            }
            if(p[ptch-'a']!=wdch || w[wdch-'a']!=ptch)
            {
                return false;
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(int i=0;i<words.size();i++)
        {
            if(match(words[i],pattern))
            {
                // cout<<"1"<<" ";
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};