class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26);
        for(auto &ch:s)
        {
            freq[ch-'a']++;
        }
        int count = 0;
        sort(freq.begin(),freq.end(),greater<int>());//sort in decreasing order
//         3 2 2 2 2 1 1
        for(int i=1;i<26;i++)
        {
            if(freq[i]>=freq[i-1] && freq[i]!=0)
            {
                freq[i]--,count++,i--;
            }
        }
        return count;
    }
};