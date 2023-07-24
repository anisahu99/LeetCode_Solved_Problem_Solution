class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int res=0;
        for(int &num:nums){
            res=max(res,num);
        }
        
        int n=nums.size();
        int l=n-2;
        long long mx=res;
        long long curr=nums[n-1];
        while(l>=0){
            if(curr>=nums[l]){
                curr=nums[l]+curr;
                mx=max(mx,curr);
            }
            else{
                curr=nums[l];
            }
            l--;
        }
        return mx;
    }
};