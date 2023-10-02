class Solution {
public:
    bool winnerOfGame(string colors) {
        int countA = 0,countB = 0;
        for(int i=1;i<colors.size();i++)
        {
            if(colors[i]==colors[i-1] && colors[i]==colors[i+1])
            {
                if(colors[i]=='A')
                {
                    countA++;
                }
                else
                {
                    countB++;
                }
            }
        }
        return countA > countB;
    }
};