class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>temp;
        for(int i=0;i<nums1.size();i++)
        {
            temp.push_back({nums2[i],nums1[i]});
        }
        sort(temp.rbegin(),temp.rend());//reverse sorting
        // we can also use greater int but it works for single value only
        // 4 3 2 1
        // 2 3 1 3
        long long ans = 0;
        long long curSum = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k-1;i++)
        {
            curSum+=temp[i].second;
            pq.push(temp[i].second);
        }
        for(int i=k-1;i<nums1.size();i++)
        {
            curSum+=temp[i].second;
            pq.push(temp[i].second);
            ans = max(ans,curSum*temp[i].first);
            curSum-=pq.top();
            pq.pop();
        }
        return ans;
    }
};