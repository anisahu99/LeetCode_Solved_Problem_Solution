class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maX=INT_MIN;
        int curr_sum=0;
        for(int &num:nums){
            curr_sum+=num;
            maX=max(maX,curr_sum);
            if(curr_sum<0){
                curr_sum=0;
            }
        }
        return maX;
    }
};