class Solution {
public:
    
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int &num:nums){
            freq[num]++;
        }
        priority_queue<int> pq;
        for(auto it:freq){
            pq.push(it.second);
        }
        while(pq.size()>1){
            int f1=pq.top();pq.pop();
            
            int f2=pq.top();pq.pop();
            f1--;
            f2--;
            if(f1){
                pq.push(f1);
            }
            if(f2){
                pq.push(f2);
            }
        }
        int ans=0;
        if(!pq.empty()) ans+=pq.top();
        return ans;
    }
};