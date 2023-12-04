class Solution {
public:
    string largestGoodInteger(string num) {
        int mx = INT_MIN;
        string ans = "";
        for(int i=0;i<num.size()-2;i++)
        {
            string str = num.substr(i,3);
            int number = stoi(str);
            if(str[0]==str[1] && str[1]==str[2] && number > mx)
            {
                ans = str;
                mx = max(mx,number);
            }
        }
        if(mx == INT_MIN) return "";
        return ans;
    }
};