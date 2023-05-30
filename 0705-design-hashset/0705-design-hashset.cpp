class MyHashSet {
public:
    vector<list<int>> buckets;
    int M;
    int getIndex(int key){
        return key%M;
    }
    MyHashSet() {
        M=1500;//given 10^4 calls  bu we take extra for difficulty.
        buckets=vector<list<int>>(M,list<int>{});
    }
    
    void add(int key) {
        int index=getIndex(key);
        auto itr=find(buckets[index].begin(),buckets[index].end(),key);
        if(itr==buckets[index].end()){
            buckets[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index=getIndex(key);
        auto itr=find(buckets[index].begin(),buckets[index].end(),key);
        if(itr!=buckets[index].end()){
            buckets[index].erase(itr);
        }
    }
    
    bool contains(int key) {
        int index=getIndex(key);
        auto itr=find(buckets[index].begin(),buckets[index].end(),key);
        if(itr!=buckets[index].end()){
            return true;
        }
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