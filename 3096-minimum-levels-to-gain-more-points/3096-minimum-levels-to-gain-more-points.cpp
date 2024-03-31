class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int sum = 0;
        int n = possible.size();
        for(int i=0;i<n;i++)
        {
            if(possible[i]==1) sum++;
            else sum--;
        }
        int prefix = 0;
        for(int i=0;i<n-1;i++)
        {
            prefix+=(possible[i]==1 ? 1 : -1);
            int s2 = sum - prefix;
            if(prefix > s2) return i+1;
        }
        return -1;
    }
};