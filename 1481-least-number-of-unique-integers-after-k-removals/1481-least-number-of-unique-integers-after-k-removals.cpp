class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>umap;
        for(int i=0;i<arr.size();i++)
        {
            umap[arr[i]]++;
        }
        vector<int>temp;
        for(auto it:umap){
            temp.push_back(it.second);
        }
        sort(temp.begin(),temp.end());
        //1 1 2 3
        int cnt = 0;
        for(int i=0;i<temp.size();i++)
        {
            cnt+=temp[i];
            if(cnt > k){
                return temp.size()-i;
            }
        }
        return 0;
    }
};