class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())
        {
            return "";
        }
        unordered_map<char,int>map1;
        unordered_map<char,int>map2;
        for(int i=0;i<t.size();i++)
        {
            map2[t[i]]++;
        }
        int count = 0,start=0,min_len = INT_MAX,start_idx = -1;
        for(int j=0;j<s.size();j++)
        {
            map1[s[j]]++;
            if(map1[s[j]]<=map2[s[j]])
            {
                count++;
            }
            if(count == t.size())
            {
                while(map1[s[start]] > map2[s[start]] || map2[s[start]]==0)
                {
                    if(map1[s[start]]>map2[s[start]])
                    {
                        map1[s[start]]--;
                        start++;
                    }
                }
                if(min_len > j-start+1)
                {
                    min_len = j-start+1;
                    start_idx = start;
                }
            }
        }
        if(start_idx==-1)
        {
            return "";
        }
        return s.substr(start_idx,min_len);
    }
};