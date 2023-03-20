class Solution {
public:
    bool checkArithmetic(vector<int>& temp)
    {
            sort(temp.begin(),temp.end());
            int diff = temp[1]-temp[0];
            for(int i=1;i<temp.size();i++)
            {
                if((temp[i]-temp[i-1])!=diff)
                {
                    return false;
                }
            }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        for(int i=0;i<l.size();i++)
        {
            vector<int>temp;
            for(int j=l[i];j<=r[i];j++)
            {
                temp.push_back(nums[j]);
            }
            ans.push_back(checkArithmetic(temp));
        }
        return ans;
    }
};