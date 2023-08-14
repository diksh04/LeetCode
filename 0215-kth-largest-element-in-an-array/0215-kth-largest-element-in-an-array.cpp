class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto it:nums)
        {
            pq.push(it);//6 5 4 3 2 1
        }
        int ans = 0;
        while(k--)
        {
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};