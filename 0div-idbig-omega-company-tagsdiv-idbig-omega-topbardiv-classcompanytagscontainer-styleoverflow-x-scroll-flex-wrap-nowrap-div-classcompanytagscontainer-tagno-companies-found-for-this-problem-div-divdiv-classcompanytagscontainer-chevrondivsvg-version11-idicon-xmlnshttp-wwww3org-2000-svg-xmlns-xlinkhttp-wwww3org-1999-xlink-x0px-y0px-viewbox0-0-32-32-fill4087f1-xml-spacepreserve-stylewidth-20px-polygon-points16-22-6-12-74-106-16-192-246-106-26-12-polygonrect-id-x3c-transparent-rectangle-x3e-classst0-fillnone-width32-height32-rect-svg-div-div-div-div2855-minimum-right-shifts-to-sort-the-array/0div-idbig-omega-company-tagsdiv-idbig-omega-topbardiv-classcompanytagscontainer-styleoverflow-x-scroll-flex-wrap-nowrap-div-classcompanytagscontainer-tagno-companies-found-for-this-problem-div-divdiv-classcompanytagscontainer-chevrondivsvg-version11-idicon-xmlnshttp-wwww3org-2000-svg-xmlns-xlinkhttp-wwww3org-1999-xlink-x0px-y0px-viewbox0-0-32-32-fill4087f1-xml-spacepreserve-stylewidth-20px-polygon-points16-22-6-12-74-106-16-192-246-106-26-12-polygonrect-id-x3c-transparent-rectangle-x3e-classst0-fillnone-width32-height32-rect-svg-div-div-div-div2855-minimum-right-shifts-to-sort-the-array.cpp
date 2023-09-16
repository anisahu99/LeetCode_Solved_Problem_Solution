class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n=nums.size();
        int mx=nums[0];
        int total_toggle=0;
        int idx=-1;
        bool flag=false;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                mx=max(mx,nums[i-1]);
                total_toggle++;
                idx=i;
            }
            else{
                if(nums[i]>mx&&total_toggle) flag=true;
                mx=max(mx,nums[i]);
            }
        }
        if(total_toggle==0) return 0;
        if(flag&&total_toggle||total_toggle>=2) return -1;
        return (n-1-idx+1);
    }
};