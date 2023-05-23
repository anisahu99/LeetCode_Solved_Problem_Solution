class KthLargest {
public:
    multiset<int,greater<int>> st;
    int K;
    KthLargest(int k, vector<int>& nums) {
        st.clear();
        K=k;
        for(int &val:nums){
            st.insert(val);
        }
    }
    
    int add(int val) {
        st.insert(val);
        int t=K;
        auto it=st.begin();
        while(--t){
            it++;
        }
        return *it;
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */