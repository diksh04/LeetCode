class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = num.size()-1;
        int carry = 0;
        vector<int>ans;
        while(i>=0 || k>0 || carry>0)
        {
            int rem = k%10;
            int elm = i>=0 ? num[i--] : 0;
            int sum = elm + rem + carry;
            ans.push_back(sum%10);
            carry = sum/10;
            k = k/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};