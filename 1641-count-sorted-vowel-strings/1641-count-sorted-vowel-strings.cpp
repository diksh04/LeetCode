class Solution {
public:
    int ans = 0;
    void solve(int n,vector<char> &v,int idx){
        if(n == 0){
            ans++;
            return;
        }
        if(idx >= v.size()) return;
        solve(n-1,v,idx);
        solve(n,v,idx+1);
    }
    int countVowelStrings(int n) {
        vector<char> v = {'a','e','i','o','u'};
        solve(n,v,0);
        return ans;
    }
};