class Solution {
public:
    int compress(vector<char>& chars) {
      char ch=chars[0];
      string s="";
      s+=ch;
      int count=1;
      for(int i=1;i<chars.size();i++)
      {
        char curr=chars[i];
        char prev=chars[i-1];  
        if(curr==prev)
        {
            count++;
        }
        else
        {
            if(count>1)
            {
                s+=to_string(count);
                count=1;
            } 
            s+=curr;
        }
      }
      if(count>1)
        {
                s+=to_string(count);
                count=1;
        } 
        for(int k = 0; k < s.size(); k++)
        {
            chars[k] = s[k];
        }
        return s.size();
    }
};
