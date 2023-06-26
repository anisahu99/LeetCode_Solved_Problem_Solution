class costCompare{
    public:
    //comparator function
    bool operator()(const pair<int,int> &p1,const pair<int,int> &p2){
        if(p1.first>p2.first){
            return true;
        }
        else if(p1.second>p2.second){
            return true;
        }
        return false;
    }
};

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int cnt=candidates;
        int n=costs.size();
        int i=0;
        int j=n-1;
        while(cnt--&&i<=j){
            if(i!=j){
                pq.push({costs[i],i});
                pq.push({costs[j],j});
            }
            else{
                pq.push({costs[i],i});
            }
            i++;
            j--;
        }
        long long ans=0;
        while(k--&&!pq.empty()){
            int idx=pq.top().second;
            int cost=pq.top().first;
            ans+=cost;
            //cout<<cost<<":"<<idx<<endl;
            pq.pop();
            if(i<n&&j>=0&&i==j){
                pq.push({costs[i],i});
                //cout<<costs[i]<<endl;
                i++;
                j--;
            }
            else if(i<n&&j>=0&&i<j){
                if(idx<i){
                    pq.push({costs[i],i});
                    //cout<<costs[i]<<endl;
                    i++;
                }
                if(idx>j){
                    pq.push({costs[j],j});
                    //cout<<costs[j]<<endl;
                    j--;
                }
            }
            
        }
        return ans;
        
    }
};