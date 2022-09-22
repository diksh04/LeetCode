class Solution {
public:
    string rev(string arr)
    {
        int start=0;
        int end=arr.size()-1;
        while(start < end)
        {
            arr[start] = arr[start] + arr[end];
            arr[end] = arr[start] - arr[end];
            arr[start] = arr[start] - arr[end];
            start++;
            end--;
        }
        return arr;
    }
    string reverseWords(string s) {
        string res="";
        int l=0,r=0;
        vector<string>ans;
        while(r!=s.size())
        {
            if(s[r]==' ')
            {
                ans.push_back(s.substr(l,r-l));
                l=r+1;
            }
            r++;
        }
        ans.push_back(s.substr(l,r-l));
        for(int i=0;i<ans.size();i++)
        {
            string s=rev(ans[i]);
            if(i!=ans.size()-1)
            {
                 res+=s+" ";
            }
            else
            {
                res+=s;
            }
        }
        return res;
    }
};