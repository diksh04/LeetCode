class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int>arr(101);
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            arr[nums[i]+50]++;
        }
        int t = x;
        for(int j=0;j<101;j++)
        {
            if(arr[j]>=t)
            {
                if((j-50) < 0)
                {
                    ans.push_back(j-50);
                }
                else // put 0 if no -ve integer found
                {
                    ans.push_back(0);
                }
                break;
            }
            else
            {
                t-=arr[j];
            }
        }
        for(int i=0;i<nums.size()-k;i++)
        {
            arr[nums[i]+50]--;
            arr[nums[i+k]+50]++;
            t = x;
            for(int j=0;j<101;j++)
            {
                if(arr[j]>=t)
                {
                    if((j-50) < 0)
                    {
                        ans.push_back(j-50);
                    }
                    else // put 0 if no -ve integer found
                    {
                        ans.push_back(0);
                    }
                    break;
                }
                else
                {
                    t-=arr[j];
                }
            }
        }
        return ans;
    }
};