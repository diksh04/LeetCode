class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string codes[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string>s;
        int n = words.size();
        for(int i=0;i<n;i++)
        {
            string str="";
            string temp = words[i];
            for(int j=0;j<temp.size();j++)
            {
                 str += codes[temp[j]-'a'];
            }
            s.insert(str);
        }
        
        return s.size();
    }
};