class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1(nums1.begin(),nums1.end());
        unordered_set<int>s2(nums2.begin(),nums2.end());
        // s1-> 1 2 3
        // s2 -> 1 2
        vector<int>a1,a2;
        for(auto it:s1)
        {
            if(s2.find(it)==s2.end())
            {
                a1.push_back(it);
            }
        }
        for(auto it:s2)
        {
            if(s1.find(it)==s1.end())
            {
                a2.push_back(it);
            }
        }
        return {a1,a2};
    }
};