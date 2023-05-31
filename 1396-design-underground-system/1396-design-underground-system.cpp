class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> CIT;
    unordered_map<string,pair<int,int>>mp;
    UndergroundSystem() {
        CIT.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        CIT[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if(CIT.find(id)!=CIT.end()){
            mp[CIT[id].first+"-"+stationName]={mp[CIT[id].first+"-"+stationName].first+1,mp[CIT[id].first+"-"+stationName].second+(t-CIT[id].second)};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        double x=mp[startStation+"-"+endStation].second;
        return double(x/mp[startStation+"-"+endStation].first);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */