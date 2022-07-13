class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>phash(26,0);
        vector<int>hash(26,0);
        int window = s1.size();
        int len = s2.size();
        if(len < window)
        {
            return false;
        }
        int left = 0,right = 0;
        while(right<window)
        {
            phash[s1[right]-'a']++;
            hash[s2[right]-'a']++;
            right++;
        }
        right--;
        while(right<len)
        {
            if(phash==hash)
            {
                return true;
            }
            right++;
            if(right!=len)
            {
                hash[s2[right]-'a']++;
            }
            hash[s2[left]-'a']--;
            left++;
        }
        return false;
    }
};