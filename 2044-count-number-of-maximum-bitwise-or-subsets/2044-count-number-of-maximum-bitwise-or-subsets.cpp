class Solution {
public:
    int res=0;
    int cnt=1;
    void solve(int i,int ans,vector<int>&nums){
        
        if(i>=nums.size()){
            if(ans>res){
                cnt=1;
                res=ans;
            }
            else if(ans==res){
                cnt++;
            }
            //cout<<ans<<endl;
            return;
        }
        
        solve(i+1,ans|nums[i],nums);
        solve(i+1,ans,nums);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        solve(0,0,nums);
        
        return cnt;
    }
};