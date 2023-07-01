class Solution {
public:
    //int ans = INT_MAX;
    //pick cookies bag or not.
    //brute force

    int solve(int pick, vector<int>& nums, vector<int>& v, int k){
        if(pick==nums.size()){
            int mx = INT_MIN;
            for(int i=0;i<k;i++){
                mx = max(mx,v[i]);
                //cout<<v[i]<<" ";
            }
            //cout<<endl;
            return mx;
        }
        int res=INT_MAX;
        for(int i=0;i<k;i++){
            v[i] += nums[pick];
            res=min(res,solve(pick+1,nums,v,k));
            v[i] -= nums[pick];
            if(v[i]==0)
                break;
        }
        return res;
    }
    
    int distributeCookies(vector<int>& nums, int k) { // nums is the cookies vector
        int n = nums.size();
        vector<int> v(k,0); // v is to store each sum of the k subsets
        return solve(0,nums,v,k);
    }
};