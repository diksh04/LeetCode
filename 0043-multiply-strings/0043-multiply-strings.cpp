class Solution {
public:
    string multiplyStr(string &s1,char ch,int idx)
    {
        int mul = ch-'0';
        string ans = "";
        int carry = 0;
        for(int i=s1.size()-1;i>=idx;i--)
        {
            int curr = (s1[i]-'0');
            int prod = curr*mul;
            prod+=carry;
            int num = prod%10;
            carry = prod/10;
            ans.push_back(num+'0');
        }
        if(carry)
        {
            ans.push_back(carry+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string add(string &s1,string &s2,int zeros)
    {
        for(int i=0;i<zeros;i++)
        {
            s2.push_back('0');
        }
        int i = s1.size()-1,j = s2.size()-1;
        int carry = 0;
        string res;
        while(i>=0 || j>=0 || carry==1)
        {
            int sum = carry;
            if(i>=0)
            {
                sum+=(s1[i]-'0');
            }
            if(j>=0)
            {
                sum+=(s2[j]-'0');
            }
            int num = sum%10;
            carry = sum/10;
            res.push_back(num+'0');
            i--;
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string multiply(string num1, string num2) {
        int n = num1.size(),m = num2.size();
        int i = 0;
        bool neg = false;
        if(num1[i]=='-')
        {
            neg = !neg;
            i++;
        }
        while(i<n && num1[i]=='0')
        {
            i++;
        }
        int j=0;
        if(num2[j]=='-')
        {
            neg = !neg;
            j++;
        }
        while(j<m && num2[j]=='0')
        {
            j++;
        }
        if(i==n || j==m)
        {
            return "0";
        }
        string ans = multiplyStr(num1,num2[m-1],i);
        // cout<<ans<<endl;
        int zeros = 0;
        for(int k=m-2;k>=j;k--)
        {
            string temp = multiplyStr(num1,num2[k],i);
            // cout<<temp<<endl;
            zeros++;
            ans = add(ans,temp,zeros);
        }
        // cout<<ans<<endl;
        i = 0;
        while(i<ans.size() && ans[i]=='0')
        {
            i++;
        }
        if(neg)
        {
            return '-'+ans.substr(i);
        }
        return ans.substr(i);
    }
};