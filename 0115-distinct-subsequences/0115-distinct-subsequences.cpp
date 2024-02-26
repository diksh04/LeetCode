class Solution {
public:   
    int numDistinct(string str, string sub) {
        int n = str.size(), m = sub.size();
      vector<double>prev(m + 1, 0),curr(m+1,0);
      prev[0] = curr[0] = 1;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (str[i-1] == sub[j-1]) {
                 curr[j] = prev[j - 1] + prev[j];
          } else {
            curr[j] = prev [j];
          }
        }
        prev = curr;
      }
      return (int)prev[m];
    }
};