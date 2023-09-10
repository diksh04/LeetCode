class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        {
            return 0;
        }
        unordered_set<int>s;
        int len = 1;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        for(auto it:s)
        {
            if(s.find(it-1)==s.end())
            {
                int x = it;
                int cnt = 1;
                while(s.find(x+1)!=s.end())
                {
                    x=x+1;
                    cnt++;
                }
                len = max(len,cnt);
            }
        }
        return len;
    }
};