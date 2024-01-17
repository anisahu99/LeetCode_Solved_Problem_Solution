class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int val:arr){
            m[val]++;
        }
        arr.clear();
        
        for(auto it:m){
            arr.push_back(it.second);
        }
        m.clear();
        for(int val:arr){
            m[val]++;
            if(m[val]>=2) return false;
        }
        return true;
    }
};