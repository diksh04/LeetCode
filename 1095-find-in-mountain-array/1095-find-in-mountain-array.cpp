/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

// find peak index
// run BS from 0 to peak index to find target idx
// if target not found then run reverse BS on array from idx+1 to n-1

class Solution {
public:
    int peakIndexInMountainArray(MountainArray &mountainArr)
    {
        int n = mountainArr.length();
        int low = 0,high = n-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return low;
    }
    int binarySearch(MountainArray &mountainArr,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid)==target)
            {
                return mid;
            }
            else if(mountainArr.get(mid)>target)
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
            if(mountainArr.get(mid)==target)
            {
                return mid;
            }
            else if(mountainArr.get(mid)>target)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int idx = peakIndexInMountainArray(mountainArr);//peak index
        int result_idx = binarySearch(mountainArr,0,idx,target);
        if(result_idx!=-1)
        {
            return result_idx;
        }
        result_idx = revBinarySearch(mountainArr,idx+1,n-1,target);
        return result_idx;
    }
};