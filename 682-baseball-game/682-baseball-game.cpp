class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>ans;
        int res=0;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="C")
            {
               ans.pop_back();
            }
            else if(ops[i]=="D")
            {
                ans.push_back(2*(ans[ans.size()-1]));
            }
            else if(ops[i]=="+")
            {
                ans.push_back(ans[ans.size()-1] + ans[ans.size()-2]);
            }
            else
            {
                ans.push_back(stoi(ops[i]));
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            res+=ans[i];
        }
        return res;
    }
};