class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n=nums.size();
        int total_toggle=0;
        int idx=-1;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                total_toggle++;
                idx=i;
            }
        }
        if(total_toggle==0) return 0;
        if(total_toggle>=2) return -1;
        if(total_toggle&nums[n-1]>nums[0]) return -1;
        return (n-1-idx+1);
    }
};