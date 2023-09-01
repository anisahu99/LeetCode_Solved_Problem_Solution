class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(int j=0;j<32;j++){
                if(i&(1<<j)) cnt++;
            }
            ans[i]=cnt;
        }
        return ans;
    }
};