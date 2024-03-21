/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    // 1,2,3,4,5,3,1
    // 0 1 2 3 4 5 6
    //         l   h   
    int findPeak(MountainArray &mountainArr)
    {
        int low = 0,high = mountainArr.length()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            // if(mountainArr.get(mid) > mountainArr.get(mid-1) && mountainArr.get(mid) > mountainArr.get(mid+1))
            // {
            //     return mid;
            // }
            if(mountainArr.get(mid) < mountainArr.get(mid+1))
            {
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return low;
    }
    int binarySearch(MountainArray &mountainArr,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid) == target) return mid;
            if(mountainArr.get(mid) > target)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return -1;
    }
    int revBinarySearch(MountainArray &mountainArr,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid) == target) return mid;
            if(mountainArr.get(mid) < target)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
//         since it is mountain arary we will try to find out peak in mountain then we will find target between 0 to peak and peak to n-1
        int n = mountainArr.length();
        int idx = findPeak(mountainArr);
        int result = binarySearch(mountainArr,0,idx,target);
        if(result!=-1)
        {
            return result;
        }
        result = revBinarySearch(mountainArr,idx+1,n-1,target);
        return result;
    }
};