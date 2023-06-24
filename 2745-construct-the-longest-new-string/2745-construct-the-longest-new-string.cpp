class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x > y)
        {
            x = y + 1;
        }
        else if(x < y)
        {
            y = x + 1;
        }
        return 2*(x+y+z);
    }
};
// x -> 2 i.e AA,AA
// y -> 5 i.e BB,BB,BB,BB,BB
// z -> 1 i.e AB
// BB AA BB AA BB AB