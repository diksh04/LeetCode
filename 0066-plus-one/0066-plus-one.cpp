class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        vector<int>ans;
        int carry = 1;
        while(i>=0 || carry > 0)
        {
            int elm = i>=0 ? digits[i--] : 0;
            int sum = elm + carry;
            ans.push_back(sum%10);
            carry = sum/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};