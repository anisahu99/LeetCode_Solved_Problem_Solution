class Solution {
public:
    double average(vector<int>& salary) {
        int mn=INT_MAX;
        int mx=INT_MIN;
        double sum=0;
        for(int val:salary){
            mx=max(mx,val);
            mn=min(mn,val);
            sum+=(double)(val);
        }
        sum-=(double)(mn+mx);
        sum=sum/(salary.size()-2);
        return sum;
    }
};