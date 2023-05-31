#define ll double
class UndergroundSystem {
public:
    unordered_map<string,vector<ll>> sum;
    unordered_map<int,pair<string,ll>>entry;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        entry[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        stationName += '-'+entry[id].first;
        auto temp = sum.find(stationName);
        if(temp == sum.end())
        {
            sum[stationName] = {1,t-entry[id].second};
        }
        else
        {
            temp->second[0]++;
            temp->second[1]+=t-entry[id].second;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        endStation += '-'+startStation;
        auto temp=sum.find(endStation);
        if(temp!=sum.end())
        {
            return ((double) temp->second[1])/(double)temp->second[0];
        }
        else
            return 0;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */