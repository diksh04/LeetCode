class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0,high = arr.size()-1;
        int ans = INT_MAX;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(arr[low]==arr[mid] && arr[mid]==arr[high])
            {
                ans = min(ans,arr[low]);
                low++;
                high--;
                continue;
            }
            if(arr[low]<=arr[mid])
            {
                ans = min(arr[low],ans);
                low = mid+1;
            }
            else
            {
                ans = min(ans,arr[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};