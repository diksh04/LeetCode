class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
            int i=0;
            stack<int>st;
            for(int x=0;x<pushed.size();x++)
            {
                st.push(pushed[x]);
                while(st.empty()!=true && st.top()==popped[i])
                {
                    st.pop();
                    i++;
                }
            }
            if(st.empty()!=true)
            {
                return false;
            }
            return true;
    }
};