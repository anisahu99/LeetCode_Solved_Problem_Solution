class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n,0);
        int left=0,end=n-1;
        int N=n;
        while(left<end){
            ans[left]=(-1*N);
            ans[end]=(N);
            N--;
            left++;
            end--;
        }
        return ans;
    }
};