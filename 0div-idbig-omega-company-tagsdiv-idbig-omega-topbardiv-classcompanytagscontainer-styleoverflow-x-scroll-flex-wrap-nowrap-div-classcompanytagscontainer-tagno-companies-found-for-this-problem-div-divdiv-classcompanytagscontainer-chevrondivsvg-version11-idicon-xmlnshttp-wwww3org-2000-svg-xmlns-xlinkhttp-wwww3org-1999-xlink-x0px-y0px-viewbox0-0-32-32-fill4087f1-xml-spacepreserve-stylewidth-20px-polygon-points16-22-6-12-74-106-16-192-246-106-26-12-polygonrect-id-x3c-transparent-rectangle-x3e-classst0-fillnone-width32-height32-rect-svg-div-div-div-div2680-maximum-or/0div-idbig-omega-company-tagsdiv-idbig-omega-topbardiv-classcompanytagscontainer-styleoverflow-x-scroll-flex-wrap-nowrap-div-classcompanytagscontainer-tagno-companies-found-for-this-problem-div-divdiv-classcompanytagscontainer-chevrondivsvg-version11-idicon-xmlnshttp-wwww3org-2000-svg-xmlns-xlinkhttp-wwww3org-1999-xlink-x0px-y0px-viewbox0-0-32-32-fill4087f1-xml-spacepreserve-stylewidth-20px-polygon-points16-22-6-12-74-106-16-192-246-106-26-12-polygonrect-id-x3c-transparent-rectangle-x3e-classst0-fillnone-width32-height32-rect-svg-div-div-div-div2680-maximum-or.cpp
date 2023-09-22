class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]|prefix[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=nums[i]|suffix[i+1];
        }
        long long res=0;
        for(int i=0;i<n;i++){
            long long temp=nums[i];
            for(int j=0;j<k;j++){
                temp=temp*2;
            }
            long long left=i==0?0:1LL*prefix[i-1];
            long long right=i==n-1?0:1LL*suffix[i+1];
            
            long long OR=temp|left|right;
            res=max(res,OR);
        }
        return res;
    }
};