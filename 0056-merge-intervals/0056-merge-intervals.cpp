class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        stack<vector<int>>st;
        st.push(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            vector<int>lm = st.top();
            vector<int>cm = intervals[i];
            if(lm[1]>=cm[0])
            {
                st.pop();
                vector<int>temp = {lm[0],max(lm[1],cm[1])};
                st.push(temp);
            }
            else
            {
                st.push(cm);
            }
        }
        stack<vector<int>>stck;
        while(!st.empty())
        {
            stck.push(st.top());
            st.pop();
        }
        while(!stck.empty())
        {
            ans.push_back(stck.top());
            stck.pop();
        }
        return ans;
    }
};