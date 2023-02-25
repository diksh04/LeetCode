class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = start^goal;
        int count = 0;
        while(res>0)
        {
            res = res&(res-1);// makes least significant 1 bit to zero
            count++;
        }
        return count;
    }
};
// method 2 
//class Solution {
// public:
//     int minBitFlips(int start, int goal) {
//         int res = start^goal;
//         int count = 0;
//         while(res>0)
//         {
//             count+=res&1;
//             res = res>>1;
//         }
//         return count;
//     }
// };