class Solution {
public:
    vector<int> t;
    int possible_jump(int i,vector<int> &nums){
        if(i>=nums.size()) return INT_MAX;
        if(i==nums.size()-1) return 0;
        if(t[i]!=-1) return t[i];
        
        int ans=INT_MAX;
        for(int j=1;j<=nums[i];j++){
            int res=possible_jump(i+j,nums);
            if(res==INT_MAX) continue;
            ans=min(ans,1+res);
        }
        return t[i]=ans;
    }
    int jump(vector<int>& nums) {
        t.resize(nums.size(),-1);
        return possible_jump(0,nums);
    }
};