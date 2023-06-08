class Solution {
public:
    
    int solve(int i,int val,vector<int>& nums){
        if(i>=nums.size()){
            return val;
        }
        int take=solve(i+1,nums[i]^val,nums);
        int not_take=solve(i+1,val,nums);
        
        return (take+not_take);
    }
    
    
    int subsetXORSum(vector<int>& nums) {
        return solve(0,0,nums);
    }
};