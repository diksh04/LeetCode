class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mp;
        mp.insert(make_pair('I',1));
        mp.insert(make_pair('V',5));
        mp.insert(make_pair('X',10));
        mp.insert(make_pair('L',50));
        mp.insert(make_pair('C',100));
        mp.insert(make_pair('D',500));
        mp.insert(make_pair('M',1000));
        int sum = 0;
        for(int i=0;i<s.size();i++)
        {
            if(i==s.size()-1 || mp[s[i]] >= mp[s[i+1]])
            {
                sum+=mp[s[i]];
            }
            else
            {
                sum+=(mp[s[i+1]]-mp[s[i]]);
                i++;
            }
        }
        return sum;
    }
};