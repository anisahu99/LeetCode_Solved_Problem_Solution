class Solution {
public:
    typedef pair<int,int> P;
    
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int &num:nums){
            freq[num]++;
        }
        auto compare=[&]( P &p1, P &p2 ){
        return p1.second<p2.second;
    };
        priority_queue<P,vector<P>,decltype(compare)> pq(compare);
        for(auto it:freq){
            pq.push(it);
        }
        while(pq.size()>1){
            int num1=pq.top().first;
            int f1=pq.top().second;pq.pop();
            
            int num2=pq.top().first;
            int f2=pq.top().second;pq.pop();
            f1--;
            f2--;
            if(f1){
                pq.push({num1,f1});
            }
            if(f2){
                pq.push({num2,f2});
            }
        }
        int ans=0;
        if(!pq.empty()) ans+=pq.top().second;
        return ans;
    }
};