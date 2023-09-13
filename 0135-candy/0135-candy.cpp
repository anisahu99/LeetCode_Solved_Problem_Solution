class Solution {
public:
    
    int solve(vector<int> &ratings){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=ratings.size();
        vector<int> candy(n,1);
        for(int i=0;i<n;i++){
            pq.push({ratings[i],i});
        }
        while(!pq.empty()){
            int idx=pq.top().second;
            pq.pop();
            if(idx-1>=0&&ratings[idx-1]<ratings[idx]){
                candy[idx]=max(candy[idx],1+candy[idx-1]);
            }
            if(idx+1<n&&ratings[idx]>ratings[idx+1]){
                candy[idx]=max(candy[idx],1+candy[idx+1]);
            }
        }
        int total_candy=0;
        for(int c:candy){
            total_candy+=c;
        }
        return total_candy;
    }
    int candy(vector<int>& ratings) {
        return solve(ratings);
    }
};