class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int noBeams = 0;
        for(int i=0;i<bank.size();i++)
        {
            int curr = 0;
            for(int j=0;j<bank[i].size();j++)
            {
                if(bank[i][j]=='1') curr++;
            }
            noBeams+=(curr*prev);
            if(curr!=0) prev = curr;
        }
        return noBeams;
    }
};