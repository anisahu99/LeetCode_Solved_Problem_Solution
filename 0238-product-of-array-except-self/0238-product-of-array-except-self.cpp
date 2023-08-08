class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int prod=1;
        int zero=0;
        int idx=-1;
        if(nums[0]==0){
            zero++;
            idx=0;
        }
        for(int i=1;i<n;i++){
            if(nums[i]==0){
                zero++;
                idx=i;
            }
            else{
                prod*=nums[i];
            }
        }
        vector<int> ans(n,0);
        if(zero>=2) return ans;
        if(zero==1){
            if(idx==0){
                ans[idx]=prod;
            }
            else{
                ans[idx]=prod*nums[0];
            }
            return ans;
        }
        ans[0]=prod;
        for(int i=1;i<n;i++){
            if(nums[i]!=0){
                ans[i]=(prod/nums[i])*nums[0];
            }else{
                ans[i]=nums[i];
            }
        }
        return ans;
    }
};