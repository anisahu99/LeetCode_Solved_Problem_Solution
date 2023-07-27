class Solution {
public:
    typedef long long ll;
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(),batteries.end());
        ll extra=0;
        for(int i=0;i<batteries.size()-n;i++){
            extra+=batteries[i];
        }
        vector<int> live;
        for(int i=batteries.size()-n;i<batteries.size();i++){
            live.push_back(batteries[i]);
        }
        for(int i=0;i<n-1;i++){
            if(extra>=(long long)(i+1)*(live[i+1]-live[i])){
                extra-=(long long)(i+1)*(live[i+1]-live[i]);
            }
            else{
                return (long long)(live[i]+(extra)/(i+1));
            }
        }
        return (long long)(live[n-1]+(extra)/(n));
    }
};