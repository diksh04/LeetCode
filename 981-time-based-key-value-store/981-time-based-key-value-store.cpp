class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
         mp[key].push_back({timestamp,value});
    } 
    
    string get(string key, int timestamp) {
         int n = mp[key].size();
        int s = 0; 
        int e = n-1;
        int ans = -1;
        while(s<=e){
            int m = s + (e-s)/2;
            if(mp[key][m].first <= timestamp){
                ans = m;
                s = m+1;
            }
            else e = m-1;
        }
        if(ans == -1)return "";
        return mp[key][ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */