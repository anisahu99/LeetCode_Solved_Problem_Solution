class Solution {
public:
    int ans = INT_MAX;
    //pick cookies bag or not.
    void solve(int pick, vector<int>& nums, vector<int>& v, int k){
        if(pick==nums.size()){
            int maxm = INT_MIN;
            for(int i=0;i<k;i++){
                maxm = max(maxm,v[i]);
            }
            ans = min(ans,maxm);
            return;
        }
        for(int i=0;i<k;i++){
            v[i] += nums[pick];
            solve(pick+1,nums,v,k);
            v[i] -= nums[pick];
        }
    }
    
    int distributeCookies(vector<int>& nums, int k) { // nums is the cookies vector
        int n = nums.size();
        vector<int> v(k,0); // v is to store each sum of the k subsets
        solve(0,nums,v,k);
        return ans;
    }
};