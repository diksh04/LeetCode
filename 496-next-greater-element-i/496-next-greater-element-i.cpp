class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)     {
        int n = nums2.size();
        unordered_map<int,int>umap;
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(st.size()>0 && nums2[i] >st.top())
            {
                st.pop();
            }
            if(st.size()==0)
            {
                umap[nums2[i]]=-1;
            }
            else
            {
                umap[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        int x = nums1.size();
        vector<int>ans(x);
        for(int i=0;i<x;i++)
        {
            if(umap.find(nums1[i])!=umap.end())
            {
                ans[i] = umap[nums1[i]];
            }
        }
        return ans;
    }
};