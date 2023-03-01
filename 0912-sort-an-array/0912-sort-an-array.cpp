class Solution {
public:
    void merge(vector<int>&nums,int l,int mid,int h)
    {
        vector<int>temp(h-l+1);
        int i=l,j=mid+1,k=0;
        while(i<=mid && j<=h)
        {
            if(nums[i]<=nums[j])
            {
                temp[k++] = nums[i++];
            }
            else
            {
                temp[k++] = nums[j++];
            }
        }
        while(i<=mid)
        {
            temp[k++] = nums[i++];
        }
        while(j<=h)
        {
            temp[k++] = nums[j++];
        }
        for(int i=0;i<k;i++)
        {
           nums[l+i] = temp[i];
        }
    }
    void mergeSort(vector<int>& nums,int l,int h)
    {
        if(l<h)
        {
            int mid = l+(h-l)/2;
            mergeSort(nums,l,mid);
            mergeSort(nums,mid+1,h);
            merge(nums,l,mid,h);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};