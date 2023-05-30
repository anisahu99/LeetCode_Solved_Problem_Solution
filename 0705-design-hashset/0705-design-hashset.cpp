class MyHashSet {
public:
    static const int sz=1e6+1;
    vector<int> dp;
    MyHashSet() {
        dp.resize(sz,0);
    }
    
    void add(int key) {
        dp[key]=1;
    }
    
    void remove(int key) {
        dp[key]=0;
    }
    
    bool contains(int key) {
        if(dp[key])
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */