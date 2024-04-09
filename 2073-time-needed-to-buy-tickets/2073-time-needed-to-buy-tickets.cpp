class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        while(true)
        {
            bool flag = false;
            for(int i=0;i<tickets.size();i++)
            {
                if(tickets[i]>0)
                {
                    time++;
                    tickets[i]--;
                }
                if(i==k && tickets[i]==0)
                {
                    flag = true;
                    break;
                }
            }
            if(flag == true) break;
        }
        return time;
    }
};