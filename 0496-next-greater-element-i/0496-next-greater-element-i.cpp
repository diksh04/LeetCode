class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),n2 = nums2.size();
        vector<int>nge(n1,-1);
        stack<int>st;
        map<int,int>mp;
        for(int i=0;i<n2;i++)
        {
            int elm = nums2[i];
            while(!st.empty() && elm > st.top())
            {
                mp[st.top()] = elm;
                st.pop();
            }
            st.push(elm);
        }
        for(int i=0;i<n1;i++)
        {
            int elm = nums1[i];
            if(mp.find(elm)!=mp.end())
            {
                nge[i] = mp[elm]; 
            }
        }
        return nge;
    }
};