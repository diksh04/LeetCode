class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = colors.size();
        for(int i=0; i<n; i++)
        {
            int j = i+1; // to compare with next balloon
            while(j<n && colors[i]==colors[j]) // while the colors are same
            { // add the minimum of the same color's time to ans and move the pointer accordingly
                if(neededTime[i]>neededTime[j]){
                    ans += neededTime[j];
                    j++;
                }
                else
                {
                    ans += neededTime[i];
                    i = j;
                    j++;
                }
            }
            i = j-1; // set the first pointer behind second as in next iteration the of for loop i = i++ will be executed
        }
        // return the ans :)
        return ans;
    }
};
