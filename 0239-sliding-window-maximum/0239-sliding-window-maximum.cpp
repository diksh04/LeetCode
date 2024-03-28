class Solution {
public:
//     1) when a new element comes,make space for it remove index which are less than equal to i-k
    // 2) if the new elem is greater that deque.back pop it
//     3) now push the current idx in deque
//     4) if(i>=k-1) push deq.front() into result array for that window
    // 5)monotonic decreasing (storing in decreasing order)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<n;i++)
        {
            while(!dq.empty() && dq.front() <= i-k)
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};