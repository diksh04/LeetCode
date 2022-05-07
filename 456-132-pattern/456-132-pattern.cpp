class Solution {
public:
    bool find132pattern(vector<int>& nums) {
       int prev = INT_MIN; 
        stack<int> stk; 
        for (int i = nums.size()-1; i >= 0; i--) {
            if (nums[i] < prev) return true; 
            while (stk.size() && stk.top() < nums[i]) {
                prev = max(prev, stk.top()); 
                stk.pop(); 
            }
            stk.push(nums[i]); 
        }
        return false; 
    }
};