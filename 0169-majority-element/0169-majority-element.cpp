class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = -1,cnt = 0;//3 3 4
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ele)
            {
                cnt++;
            }
            else if(cnt == 0)
            {
                ele = nums[i];//
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        cnt = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ele)
            {
                cnt++;
            }
        }
        if(cnt >= nums.size()/2)
        {
            return ele;
        }
        return -1;
    }
};