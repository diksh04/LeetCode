class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long count = 0;
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        
        vector<int>odd1,odd2,even1,even2;
    
        for(int i=0;i<nums.size();i++)// 6 8 12
        {
            if(nums[i]%2==0)
            {
                even1.push_back(nums[i]);//6 8 12
            }
            else
            {
                odd1.push_back(nums[i]);//nothing
            }
        }
        for(int i=0;i<target.size();i++)// 2 10 14
        {
            if(target[i]%2==0)
            {
                even2.push_back(target[i]);//2 10 14
            }
            else
            {
                odd2.push_back(target[i]);//nothing
            }
        }
        for(int i=0;i<odd1.size();i++)
        {
            if(odd1[i]<odd2[i])
            {
                count+=((odd2[i]-odd1[i])/2);
            }
        }
        for(int i=0;i<even1.size();i++)// even1=[6 8 12] even2 = [2 10 14]
        {
            if(even1[i]<even2[i])
            {
                count+= ((even2[i]-even1[i])/2);
            }
        }
        return count;
    }
};