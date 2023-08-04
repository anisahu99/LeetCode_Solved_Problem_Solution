class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int>comp;
        for(int i=0;i<n;i++)
            comp.push_back(abs(s[i]-t[i]));

        int start = 0, end = 0, ans=0;
        int cost = maxCost;
        while(end<n){
            if(comp[end]>maxCost){
                if(end==n-1)
                    break;
                cost = maxCost;
                end++;
                start = end;
            }
            else if(cost-comp[end]>=0){
                cost -= comp[end];
                end++;
            }
            else if(cost-comp[end]<=0){
                cost += comp[start];
                start++;
            }
            ans = max(ans, end-start);
        }
        return ans;
    }
};
