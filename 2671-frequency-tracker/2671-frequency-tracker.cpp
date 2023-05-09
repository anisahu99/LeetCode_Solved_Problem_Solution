class FrequencyTracker {
public:
    unordered_map<int,int> mp;
    unordered_map<int,unordered_set<int>> freq;
    FrequencyTracker() {
        mp.clear();
        freq.clear();
    }
    
    void add(int number) {
        if(mp.find(number)!=mp.end()){
            int f=mp[number];
            freq[f].erase(number);
        }
        mp[number]++;
        freq[mp[number]].insert(number);
    }
    
    void deleteOne(int number) {
        if(mp.find(number)!=mp.end()){
            if(mp[number]>1){
                int f=mp[number];
                freq[f].erase(number);
                mp[number]--;
                freq[mp[number]].insert(number);
            }
            else{
                int f=mp[number];
                freq[f].erase(number);
                mp.erase(number);
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        if(freq[frequency].size()>0)
            return true;
        return false;
    }
};