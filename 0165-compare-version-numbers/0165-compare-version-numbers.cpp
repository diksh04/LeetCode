class Solution {
public:
    vector<string> getTokens(string version)
    {
        stringstream v(version);
        vector<string>versionTokens;
        string tokenV = "";
        while(getline(v,tokenV,'.')){
            versionTokens.push_back(tokenV);
        }
        return versionTokens;
    }
    int compareVersion(string version1, string version2) {
        vector<string>v1 = getTokens(version1);
        vector<string>v2 = getTokens(version2);
        
        int m = v1.size(),n = v2.size();
        int i = 0;
        while(i<m || i<n)
        {
            int a = i < m ? stoi(v1[i]) : 0;
            int b = i < n ? stoi(v2[i]) : 0;
            if(a > b) return 1;
            else if(b > a) return -1;
            else i++;
        }
        return 0;
    }
};