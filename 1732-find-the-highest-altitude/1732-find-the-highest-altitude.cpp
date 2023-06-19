class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        gain.push_back(0);
        int n=gain.size();
        int temp=gain[0];
        gain[0]=0;
        int mx=INT_MIN;
        for(int i=1;i<n;i++){
            int t=gain[i];
            gain[i]=temp+gain[i-1];
            mx=max(mx,gain[i]);
            temp=t;
        }
        return mx<0?0:mx;
    }
};