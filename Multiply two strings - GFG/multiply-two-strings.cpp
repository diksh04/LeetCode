//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiply(string &s1,char ch,int idx)
    {
        int mul = ch-'0';
        int carry = 0;
        string temp = "";
        for(int i=s1.size()-1;i>=idx;i--)
        {
            int curr = (s1[i]-'0');
            int prod = curr * mul;
            prod+=carry;
            int num = prod%10;
            carry = prod/10;
            temp.push_back(num+'0');
        }
        if(carry)
        {
            temp.push_back(carry+'0');
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    string add(string &ans,string &temp,int zerosAppend)
    {
        for(int i=0;i<zerosAppend;i++)
        {
            temp.push_back('0');
        }
        int n = ans.size(),m =temp.size();
        int i = n-1,j=m-1;
        int carry = 0;
        string final;
        while(i>=0 || j>=0 || carry==1)
        {
            int sum = carry;
            if(i>=0)
            {
                sum+=(ans[i]-'0');
            }
            if(j>=0)
            {
                sum+=(temp[j]-'0');
            }
            int num = sum%10;
            carry = sum/10;
            final.push_back(num+'0');
            i--;
            j--;
        }
        reverse(final.begin(),final.end());
        return final;
    }
    string multiplyStrings(string s1, string s2) {
       //Your code here
       bool neg = false;
       int n = s1.size(),m = s2.size();
       int i=0;
       if(s1[i]=='-')
       {
           neg = !neg;
           i++;
       }
       while(i<n && s1[i]=='0')
       {
           i++;
       }
       int j = 0;
       if(s2[j]=='-')
       {
           neg = !neg;
           j++;
       }
       while(j<m && s2[j]=='0')
       {
           j++;
       }
       if(i==n || j==m)
       {
           return "0";
       }
       string ans = multiply(s1,s2[m-1],i);
    //   cout<<ans<<endl;
       int zerosAppend = 0;
       for(int k=m-2;k>=j;k--)
       {
           string temp = multiply(s1,s2[k],i);
        //   cout<<temp<<endl;
          zerosAppend++;
          ans = add(ans,temp,zerosAppend);
       }
        i=0;
       while(i<ans.length() && ans[i]=='0') i++;
       return (neg?'-'+ans.substr(i):ans.substr(i));
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends