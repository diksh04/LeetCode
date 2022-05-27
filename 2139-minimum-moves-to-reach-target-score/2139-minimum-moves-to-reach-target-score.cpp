class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int steps = 0;
        while(target>1 )
        {
            if(target%2!=0)
            {
                target--;
                steps++;
            }
            else
            {
                if(maxDoubles!=0)
                {
                    target/=2;
                    steps++;
                    maxDoubles--;
                }
                else
                {
                    return (target+steps-1);
                }
            }
        }
        return steps;
        // 19-> 18(1)->9(2)->8(3)->4(4)->3(5)->2(6)->1(7)
    }
};