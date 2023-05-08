class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int take=nums[0];
        int not_take=0;
        for(int i=1;i<n;i++){
            int newTake=not_take+nums[i];
            int newNotTake=max(take,not_take);
            take=newTake;
            not_take=newNotTake;
        }
        return max(take,not_take);
    }
};