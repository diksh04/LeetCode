class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
          sort(arr.begin(),arr.end());
          stack<vector<int>>st;
          st.push(arr[0]);
          for(int i=1;i<arr.size();i++)
          {
            vector<int>cm = arr[i];// current meeting
            vector<int>lm = st.top();// last meeting
            // 0 index is starting point and 1 is ending point
            if(lm[1]>=cm[0])
            {
                // overlap and merge
                st.pop();
                vector<int>merge = { lm[0], max(lm[1],cm[1])};
                st.push(merge);
            }
            else
            {
                st.push(cm);
            }
          }
        // reverse
      stack<vector<int>>newSt;
      while(st.size()>0)
      {
        newSt.push(st.top());
        st.pop();
      }
    vector<vector<int>>ans;
    while(newSt.size()>0)
      {
          vector<int>final = newSt.top();
          newSt.pop();
          ans.push_back(final);
      }
        return ans;
    }
};