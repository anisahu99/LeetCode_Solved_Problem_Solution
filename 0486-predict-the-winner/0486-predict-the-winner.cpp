class Solution {
public:
    int solve_for_1(vector<int>& nums,int i,int j,bool turn){
        if(i>j) return 0;
        if(i==j) return nums[i];
        
        if(turn){
            return max(nums[i]+solve_for_1(nums,i+1,j,false),nums[j]+solve_for_1(nums,i,j-1,false));
        }
        else{
            return min(solve_for_1(nums,i+1,j,true),solve_for_1(nums,i,j-1,true));
        }
        return 0;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int total=0;
        for(int& num:nums){
            total+=num;
        }
        int ans=solve_for_1(nums,0,nums.size()-1,true);
        cout<<ans<<endl;
        return total-ans>ans?false:true;
    }
};