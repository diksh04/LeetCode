class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int elm1 = -1,elm2 = -1;
        int cnt1 = 0,cnt2 = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(elm1==nums[i])
            {
                cnt1++;
            }
            else if(elm2 == nums[i])
            {
                cnt2++;
            }
            else if(cnt1 == 0)
            {
                elm1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0)
            {
                elm2 = nums[i];
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0,cnt2 = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==elm1) cnt1++;
            else if(nums[i] == elm2) cnt2++;
        }
        vector<int>ans;
        if(cnt1 > nums.size()/3)
        {
            ans.push_back(elm1);
        }
        if(cnt2 > nums.size()/3)
        {
            ans.push_back(elm2);
        }
        return ans;
    }
};