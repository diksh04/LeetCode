class Solution {
public:

    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score=0;
        int res = 0;
        int i=0,j=tokens.size()-1;
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                power-=tokens[i++];
                score++;
                res = max(res,score);
            }
            else if(score > 0)
            {
                score--;
                power+=tokens[j--];
            }
            else
            {
                break;
            }
        }
        return res;
    }
};
// 100 200 300 400 power = 300 score = 0
//         i