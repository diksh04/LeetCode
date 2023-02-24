class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int mn = INT_MAX;
        int diff = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=0)
            {
                nums[i]*=2;
            }
            pq.push(nums[i]);
            mn = min(mn,nums[i]);
        }
        while(pq.top()%2==0)
        {
            int mx = pq.top();
            pq.pop();
            diff = min(diff,mx-mn);
            mn = min(mn,mx/2);
            pq.push(mx/2);
        }
        return min(diff,pq.top()-mn);
    }
};