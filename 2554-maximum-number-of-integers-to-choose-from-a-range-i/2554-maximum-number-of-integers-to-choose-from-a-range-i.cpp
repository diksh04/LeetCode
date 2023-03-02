class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // sort(banned.begin(),banned.end());
        unordered_map<int,int>umap;
        for(int i=0;i<banned.size();i++)
        {
            umap[banned[i]]++;
        }
        int sum=0;
        int count = 0;
        for(int i=1;i<=n;i++)
        {
            if(umap.find(i)==umap.end())
            {
                if(i+sum<=maxSum)
                {
                    sum+=i;
                    count++;
                }
            }
            if(sum>maxSum)
            {
                break;
            }
        }
        return count;
    }
};